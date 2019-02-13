### Problem statement
Create List of List (2D List) Iterator
> Leetcode #251 Flatten 2D Vector
Leetcode #341 Flatten Nested List Iterator

> For example, Given 2d vector = [ [1,2], [3], [4,5,6] ]
By calling next repeatedly until hasNext returns false, the order of elements returned by next should be:
[1,2,3,4,5,6].
• boolean hasNext() return true if there is another element in the set
• int next() return the value of the next element in the array
• void remove()
o remove the last element returned by the iterator.
o That is, remove the element that the previous next() returned.
o This method can be called only once per call to next(), otherwise an exception will be
thrown.
Removes from the underlying collection the last element returned by this iterator (optional operation).
This method can be called only once per call to next(). The behavior of an iterator is unspecified if the
underlying collection is modified while the iteration is in progress in any way other than by calling this
method.
So the remove() method actually removes the element returned from the next().

``` C++
class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec2d) {
        cp = vec2d;
        rowId = 0;
        colId = 0;
    }

    int next() {
        return cp[rowId][colId++];
    }

    bool hasNext() {
        while (rowId != cp.size() && colId == cp[rowId].size()) {
            rowId++;
            colId = 0;
        }
        return rowId != cp.size();
    }
private:
    vector<vector<int>> cp;
    int rowId;
    int colId;
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */

class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec2d) {
        // Initialize your data structure here
        begin = vec2d.begin();
        end = vec2d.end();
        pos = 0;
    }

    int next() {
        // Write your code here
        hasNext();
        return (*begin)[pos++];
    }

    bool hasNext() {
        // Write your code here
        while (begin != end && pos == (*begin).size())
            begin++, pos = 0;
        return begin != end;
    }

private:
    vector<vector<int>>::iterator begin, end;
    int pos;
};

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer,
 *     // rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds,
 *     // if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds,
 *     // if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        // Initialize your data structure here.
        for(int i = nestedList.size() - 1; i >= 0; --i){
            st.push(nestedList[i]);
        }
    }

    // @return {int} the next element in the iteration
    int next() {
        // Write your code here
        int temp = st.top().getInteger();
        st.pop();
        return temp;
    }

    // @return {boolean} true if the iteration has more element or false
    bool hasNext() {
        // Write your code here
        while(!st.empty()) {
            NestedInteger t = st.top();
            if(t.isInteger()){
                return true;
            }

            vector<NestedInteger> list = t.getList();
            st.pop();
            for(int i = list.size() - 1; i >= 0; --i){
                st.push(list[i]);
            }
        }
        return false;
    }
    private:
    stack<NestedInteger> st;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) v.push_back(i.next());
 */

```

