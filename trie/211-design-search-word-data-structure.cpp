// https://leetcode.com/problems/design-add-and-search-words-data-structure/description/

class WordDictionary {
public:
    const static int maxNodes = 26;
    WordDictionary *nodes[maxNodes];
    bool isWord;
    
    WordDictionary():isWord(false) {
        for(int i=0; i<maxNodes; i++) {
            nodes[i]  = nullptr;
        }    
    }
    
    void addWord(string word) {
        WordDictionary *next = this;
        for(int i=0; i<word.length(); i++) {
            int index = word[i] - 'a';
            if(next->nodes[index] == nullptr) {
                next->nodes[index] = new WordDictionary();
            }

            next = next->nodes[index];
        }

        if(next) {
            next->isWord = true;
        }
    }
    
    bool find(WordDictionary *node, int index, string &word) {
            if(index >= word.length()) {
                return node->isWord;
            }

            if(word[index] == '.') {
                for(int j=0; j<maxNodes; j++) {
                    if(node->nodes[j] != nullptr && find(node->nodes[j], index+1, word)) {
                        return true;
                    }
                }
                return false;
            } else {
                int idx = word[index] - 'a';

                if(node->nodes[idx] == nullptr) {
                    return false;
                } else {
                    return find(node->nodes[idx], index+1, word);
                }
            }
    }

    bool search(string word) {
         return find(this, 0, word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
