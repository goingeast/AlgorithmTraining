/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 *
 * https://leetcode.com/problems/course-schedule/description/
 *
 * algorithms
 * Medium (36.69%)
 * Total Accepted:    189.9K
 * Total Submissions: 516.9K
 * Testcase Example:  '2\n[[1,0]]'
 *
 * There are a total of n courses you have to take, labeled from 0 to n-1.
 * 
 * Some courses may have prerequisites, for example to take course 0 you have
 * to first take course 1, which is expressed as a pair: [0,1]
 * 
 * Given the total number of courses and a list of prerequisite pairs, is it
 * possible for you to finish all courses?
 * 
 * Example 1:
 * 
 * 
 * Input: 2, [[1,0]] 
 * Output: true
 * Explanation: There are a total of 2 courses to take. 
 * To take course 1 you should have finished course 0. So it is possible.
 * 
 * Example 2:
 * 
 * 
 * Input: 2, [[1,0],[0,1]]
 * Output: false
 * Explanation: There are a total of 2 courses to take. 
 * To take course 1 you should have finished course 0, and to take course 0 you
 * should
 * also have finished course 1. So it is impossible.
 * 
 * 
 * Note:
 * 
 * 
 * The input prerequisites is a graph represented by a list of edges, not
 * adjacency matrices. Read more about how a graph is represented.
 * You may assume that there are no duplicate edges in the input
 * prerequisites.
 * 
 * 
 */
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector< unordered_set<int> > graph(numCourses, unordered_set<int>());
        vector<int> indegree(numCourses,0);
        
        for(auto p : prerequisites){
            ++indegree[p.first];
            graph[p.second].insert(p.first);
        }

        queue<int> bfs;

        for(int i = 0; i < numCourses; ++i){
        	if(indegree[i] == 0)
        		bfs.push(i);
        }
        int count = 0;
        while(!bfs.empty()){
        	int vertex = bfs.front();
        	bfs.pop();
        	++count;
        	for(auto it : graph[vertex]){
        		--indegree[it];
        		if(indegree[it] == 0){
        			bfs.push(it);
        		}
        	}
        }
        return count == numCourses;
    }
};

