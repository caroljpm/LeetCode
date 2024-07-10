/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    unordered_set<int> visited;
    unordered_map<int, Node*> clonedMap;
    queue<Node*> qNode;

public:
    Node* createNode(int val) { return new Node(val); }
   
    void addVisitedNode(int val) {
        if(visited.find(val) == visited.end()) {
            visited.insert(val);
        }
    }

    bool isVisited(int val) {
        if(visited.find(val) == visited.end()) {
            return false;
        } else {
            return true;
        }
    }

    Node* cloneGraph(Node* node) {
        if(node) {
            qNode.push(node);
        }

        while (!qNode.empty()) {
            int val = qNode.front()->val;

            if (clonedMap.find(val) == clonedMap.end()) {
                clonedMap[val] = createNode(val);
            }
            addVisitedNode(val);

            vector<Node*> n;
            for (auto &neigh : qNode.front()->neighbors) {
                int nval = neigh->val;
                if (clonedMap.find(nval) == clonedMap.end()) {
                    clonedMap[nval] = createNode(nval);
                }
                clonedMap[val]->neighbors.emplace_back(clonedMap[nval]);
                if(!isVisited(nval)) {
                    qNode.push(neigh);
                }
                addVisitedNode(nval);
            }

            qNode.pop();
        }
        
        if(node) {
            return clonedMap[node->val];
        } else {
            return nullptr;
        }
    }
};