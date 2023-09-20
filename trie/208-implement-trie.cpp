// https://leetcode.com/problems/implement-trie-prefix-tree/

class Trie {
public:
    int maxChars=26;
    Trie *nodes[26];
    bool isWord;
    char ch;

    Trie() : isWord(false){
        for(int i=0; i<maxChars; i++) {
            nodes[i] = nullptr;
        }
    }
    
    void insert(string word) {
        Trie *next = this;
        for(int i=0; i<word.size(); i++) {
            int index = word[i] - 'a';
            
            //std::cout << "Index :" << index << "," << next->nodes << std::endl;
            if(next->nodes[index] == nullptr) {
                next->nodes[index] = new Trie();
                next->nodes[index]->ch = word[i];
            }
            next = next->nodes[index];
        }
  
        if(next) {
            next->isWord = true;
        }
    }
    
    bool search(string word) {
        Trie *next = this;

        for(int i=0; i<word.size(); i++) {
            int index = word[i] - 'a';
            if(next->nodes[index] == nullptr) {
                return false;
            }

            if(next->nodes[index]->ch != word[i]) {
                return false;
            } else {
                next = next->nodes[index];
            }
        }

        if(next && next->isWord){
            return true;
        } else {
            return false;
        }
    }
    
    bool startsWith(string prefix) {
        Trie *next = this;

        for(int i=0; i<prefix.size(); i++) {
            int index = prefix[i] - 'a';
            if(next->nodes[index] == nullptr) {
                return false;
            }
            
            if(next->nodes[index]->ch != prefix[i]) {
                return false;
            }

            next = next->nodes[index];
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
