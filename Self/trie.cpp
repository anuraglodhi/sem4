#include <iostream>
#include <unordered_map>
using namespace std;

class TrieNode {
    public:
    bool isEnd;
    unordered_map<char, TrieNode*> children;
};

class Trie {
    TrieNode* root;
    public:

    Trie() {
        root = new TrieNode();
    }

    void insert(string s) {
        TrieNode* curr = root;
        for (int i = 0, n = s.size(); i < n; i++) {
            if (!curr->children[s[i]]) curr->children[s[i]] = new TrieNode();
            curr = curr->children[s[i]];
        }
        curr->isEnd = true;
    }

    bool search(string s) {
        TrieNode* curr = root;
        for (int i = 0, n = s.size(); i < n; i++) {
            if (!curr->children[s[i]]) {
                return false;
            }
            curr = curr->children[s[i]];
        }
        if (curr->isEnd) return true;
        return false;
    }

};

int main() {
    Trie trie;
    trie.insert("bob");
    trie.insert("bobcat");
    trie.insert("hello");
    cout << trie.search("guy") << endl;
    cout << trie.search("bob") << endl;
    cout << trie.search("bobcat") << endl;
    cout << trie.search("hel") << endl;
    cout << trie.search("hello") << endl;
}