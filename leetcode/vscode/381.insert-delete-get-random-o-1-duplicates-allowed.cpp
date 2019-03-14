/*
 * @lc app=leetcode id=381 lang=cpp
 *
 * [381] Insert Delete GetRandom O(1) - Duplicates allowed
 *
 * https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/description/
 *
 * algorithms
 * Hard (31.45%)
 * Total Accepted:    38.3K
 * Total Submissions: 121.5K
 * Testcase Example:  '["RandomizedCollection","insert","insert","insert","getRandom","remove","getRandom"]\n[[],[1],[1],[2],[],[1],[]]'
 *
 * Design a data structure that supports all following operations in average
 * O(1) time.
 * Note: Duplicate elements are allowed.
 * 
 * 
 * insert(val): Inserts an item val to the collection.
 * remove(val): Removes an item val from the collection if present.
 * getRandom: Returns a random element from current collection of elements. The
 * probability of each element being returned is linearly related to the number
 * of same value the collection contains.
 * 
 * 
 * 
 * Example:
 * 
 * // Init an empty collection.
 * RandomizedCollection collection = new RandomizedCollection();
 * 
 * // Inserts 1 to the collection. Returns true as the collection did not
 * contain 1.
 * collection.insert(1);
 * 
 * // Inserts another 1 to the collection. Returns false as the collection
 * contained 1. Collection now contains [1,1].
 * collection.insert(1);
 * 
 * // Inserts 2 to the collection, returns true. Collection now contains
 * [1,1,2].
 * collection.insert(2);
 * 
 * // getRandom should return 1 with the probability 2/3, and returns 2 with
 * the probability 1/3.
 * collection.getRandom();
 * 
 * // Removes 1 from the collection, returns true. Collection now contains
 * [1,2].
 * collection.remove(1);
 * 
 * // getRandom should return 1 and 2 both equally likely.
 * collection.getRandom();
 * 
 * 
 */
class RandomizedCollection {
public:
    unordered_map<int, unordered_set<int> > mp;
    vector<int> vc;
    /** Initialize your data structure here. */
    RandomizedCollection() {
        srand(time(NULL));
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        vc.push_back(val);
        mp[val].insert(vc.size() - 1);
        return mp[val].size() == 1;

    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (!mp[val].empty()) {
            int idx = *mp[val].begin();
            mp[val].erase(idx);
            if (vc.size() - 1 != idx) {
                vc[idx] = vc.back();
                mp[vc.back()].erase(vc.size()-1);
                mp[vc.back()].insert(idx);
            }
            vc.pop_back();
            return true;
        }
        return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return vc[rand()%vc.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */

