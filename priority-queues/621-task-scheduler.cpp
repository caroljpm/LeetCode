// https://leetcode.com/problems/task-scheduler/description/

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> tasksMap;
        for(auto &ch: tasks) {
            tasksMap[ch]++;
        }

        priority_queue<int> taskPQ;
        queue<pair<int, int>> nextTaskQ;
        int interval = 0;

        for(auto &it : tasksMap) {
            taskPQ.push(it.second);
        }

        while(!(taskPQ.empty() && nextTaskQ.empty())) {
            interval++;

            if(nextTaskQ.size()) {
                auto &nextPair = nextTaskQ.front();
                if(nextPair.second == interval) {
                    taskPQ.push(nextPair.first);
                    nextTaskQ.pop();
                }
            }

            if(taskPQ.size()) {
                auto nextTask = taskPQ.top();
                if(--nextTask) {
                    nextTaskQ.push(make_pair(nextTask, interval+n+1));
                }
                taskPQ.pop();
            }
        }

        return interval;
    }
};
