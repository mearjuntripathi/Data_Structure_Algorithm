#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    TrieNode* child[26];
    bool isEnd;

    TrieNode() {
        isEnd = false;

        for (int i = 0; i < 26; i++) {
            child[i] = nullptr;
        }
    }
};

class Trie {
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* curr = root;

        for (char ch : word) {
            int index = ch - 'a';

            if (curr->child[index] == nullptr) {
                curr->child[index] = new TrieNode();
            }

            curr = curr->child[index];
        }

        curr->isEnd = true;
    }

    bool search(string word) {
        TrieNode* curr = root;

        for (char ch : word) {
            int index = ch - 'a';

            if (curr->child[index] == nullptr) {
                return false;
            }

            curr = curr->child[index];
        }

        return curr->isEnd;
    }

    bool startsWith(string prefix) {
        TrieNode* curr = root;

        for (char ch : prefix) {
            int index = ch - 'a';

            if (curr->child[index] == nullptr) {
                return false;
            }

            curr = curr->child[index];
        }

        return true;
    }
};

int main() {
    Trie trie;

    trie.insert("apple");
    trie.insert("app");
    trie.insert("application");
    trie.insert("banana");

    cout << trie.search("apple") << endl;
    cout << trie.search("app") << endl;
    cout << trie.search("appl") << endl;

    cout << trie.startsWith("app") << endl;
    cout << trie.startsWith("ban") << endl;
    cout << trie.startsWith("cat") << endl;

    return 0;
}
