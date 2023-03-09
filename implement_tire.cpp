class Trie {
public:
    bool isIn[26] = {false};
    bool isTerminal[26] = {false};
    Trie* sibling[26] = {NULL};
    Trie() {
    }
    
    void insert(string word) {
        Trie* cur = this;
        int limit = word.size();
        for(int i = 0; i < limit; i++)
        {
            int idx = word[i] - 'a';
            cur -> isIn[idx] = true;
            if(i == limit - 1)
            {
                cur -> isTerminal[idx] = true;
            }
            if(cur -> sibling[idx] == NULL)
            {
                cur -> sibling[idx] = new Trie();
            }
            cur = cur -> sibling[idx];
        }
    }
    
    bool search(string word) {
        Trie* cur = this;
        int limit = word.size();
        for(int i = 0; i < limit; i++)
        {
            int idx = word[i] - 'a';
            if(cur == NULL || cur -> isIn[idx] == false) return false;
            if(i== limit - 1 && cur -> isTerminal[idx] == false) return false;
            cur = cur -> sibling[idx];
        }
        return true;
    }
    
    bool startsWith(string prefix) {
        Trie* cur = this;
        int limit = prefix.size();
        for(int i = 0; i < limit; i++)
        {
            int idx = prefix[i] - 'a';
            if(cur == NULL || cur -> isIn[idx] == false) return false;
            cur = cur -> sibling[idx];
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