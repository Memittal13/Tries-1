//Time O(n)
//Space O(n)
//Leetcode: yes
//Issue seen: none

class TrieNode {
public:
    TrieNode* children[26];
    bool isEnd;
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isEnd = false;
    }
};
class Trie {
public:
    TrieNode* root;
    Trie() { 
       root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* node = root;
        int temp=0;
        for (int i = 0; i < word.length(); i++) {
            temp = word[i] - 'a';
            if (node->children[temp] == NULL) {
                node->children[temp] = new TrieNode();
            }
            node = node->children[temp];
        }
        node->isEnd = true;
    }

    bool search(string word ) {
        TrieNode* node = root;
        int temp=0;

        for (int i = 0; i < word.length(); i++) {
            temp = word[i] - 'a';
            if (node->children[temp] == NULL) {
                return false;
            }
            node = node->children[temp];
        }
        return node->isEnd;
    }

    bool startsWith(string prefix) {
        TrieNode* node = root;
        int temp=0;

        for (int i = 0; i < prefix.length(); i++) {
            temp = prefix[i] - 'a';
            if (node->children[temp] == NULL) {
                return false;
            }
            node = node->children[temp];
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
