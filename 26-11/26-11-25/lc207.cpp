#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);

        for(const auto& r : prerequisites) {
            int a = r[0], b = r[1];
            graph[b].push_back(a);
            indegree[a]++;
        }

        queue<int> q;
        for(int i = 0; i < numCourses; ++i) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        int taken = 0;

        while(!q.empty()) {
            int course = q.front();
            q.pop();

            taken++;

            for(int next : graph[course]) {
                indegree[next]--;

                if(indegree[next] == 0) {
                    q.push(next);
                }
            }
        }

        return taken == numCourses;
    }
};

int main(void) {

    Solution s;
    vector<vector<int>> prerequisites = {{1, 0}};
    bool res = s.canFinish(2, prerequisites);
    
    return 0;
}