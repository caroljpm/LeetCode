// https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/description/
class Solution {
    stack<int> next;
    undordered_set<int> visited;
public:
    /**
     * @param n: the number of vertices
     * @param edges: the edges of undirected graph
     * @return: the number of connected components
     */
    int countComponents(int n, vector<vector<int>> &edges) {
        vector<int> adjList[n];
        for(auto &edge : edges) {
            adjList[edge[0]].emplace_back(edge[1]);
            adjList[edge[1]].emplace_back(edge[0]);
        }

        int connected = 0;
        for(int i=0; i<n; i++) {
            if(visited.find(i) == visited.end()) {
                next.push(i);
                ++connected;
                dfs();
            }
        }

        return connected;
    }

    void dfs() {
        while(!next.empty()) {
            int val = next.front();
            next.pop();

            if(visited.find() == visited.end()) {
                visited.insert(val);
                for(auto &n : adjList[val]) {
                    next.push(n);
                }
            }
        }

        dfs();

};