// https://leetcode.com/problems/course-schedule/description/
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree(numCourses, 0);
        vector<int> adjList[numCourses];
        queue<int> courses;

        vector<int> topo;

        for(auto &req : prerequisites) {
            adjList[req[1]].emplace_back(req[0]);
            inDegree[req[0]]++;
        }

        for(int i=0; i<numCourses; i++) {
            if(inDegree[i] == 0) {
                courses.push(i);
            }
        }

        while(!courses.empty()) {
            int course = courses.front();
            courses.pop();

            topo.emplace_back(course);

            for(auto &l : adjList[course]) {
                inDegree[l]--;

                if(inDegree[l] == 0) {
                    courses.push(l);
                }
            }
        }

        return topo.size() == numCourses;
    }
};