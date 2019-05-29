/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 *
 * https://leetcode.com/problems/lru-cache/description/
 *
 * algorithms
 * Hard (24.47%)
 * Total Accepted:    276.4K
 * Total Submissions: 1.1M
 * Testcase Example:  '["LRUCache","put","put","get","put","get","put","get","get","get"]\n[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]'
 *
 * 
 * Design and implement a data structure for Least Recently Used (LRU) cache.
 * It should support the following operations: get and put.
 * 
 * 
 * 
 * get(key) - Get the value (will always be positive) of the key if the key
 * exists in the cache, otherwise return -1.
 * put(key, value) - Set or insert the value if the key is not already present.
 * When the cache reached its capacity, it should invalidate the least recently
 * used item before inserting a new item.
 * 
 * 
 * Follow up:
 * Could you do both operations in O(1) time complexity?
 * 
 * Example:
 * 
 * LRUCache cache = new LRUCache( 2 capacity );
 * 
 * cache.put(1, 1);
 * cache.put(2, 2);
 * cache.get(1);       // returns 1
 * cache.put(3, 3);    // evicts key 2
 * cache.get(2);       // returns -1 (not found)
 * cache.put(4, 4);    // evicts key 1
 * cache.get(1);       // returns -1 (not found)
 * cache.get(3);       // returns 3
 * cache.get(4);       // returns 4
 * 
 * 
 */
class LRUCache {
public:
    struct LRUNode {
        int value;
        int key;
        
        LRUNode(int k, int v) : key(k), value(v) {}
    };

    LRUCache(int capacity) : cap(capacity) {
        
    }
    
    int get(int key) {
        if (!kv.count(key)) {
            return -1;
        }
        move_front(key);
        return values.front().value;
    }
    
    void put(int key, int value) {
        if (!kv.count(key)) {
            values.emplace_front(key, value);
            kv[key] = values.begin();
            if (values.size() > cap) {
                kv.erase(values.back().key);
                values.pop_back();
            }
        } else {
            kv[key]->value = value;
            move_front(key);
        }
    }
private:
    void move_front(int key) {
        values.splice(values.begin(), values, kv[key]);
        kv[key] = values.begin();
    }
    
    int cap;
    std::list<LRUNode> values;
    std::unordered_map<int, list<LRUNode>::iterator> kv;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

