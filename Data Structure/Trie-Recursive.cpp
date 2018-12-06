#include <bits/stdc++.h>
using namespace std;

/// Trie Recursion based implementation
/// Create the root (root = new Trie())
/// Use insert and search accordingly
/// At the end call delete_trie() to delete all the nodes
/// Done for only digits by default

#define SIZE 10

class Trie {
    bool ed;
    Trie *child[SIZE];
    /// If ed is true, a word is finished here

public:
    Trie() {
        ed = false;
        for(int i=0; i<SIZE; i++) {
            child[i] = NULL;
        }
    }

    /// Delete to save memory
    void delete_trie() {
        for(int i=0; i<SIZE; i++) {
            if(child[i]!=NULL) {
                child[i]->delete_trie();
                delete child[i];
            }
        }
    }

    void insert(string &word, int pos) {
        if(pos==(int)word.length()) {
            ed = true;
            return;
        }
        int c = (int)(word[pos] - '0'); ///change here
        if(child[c] == NULL) {
            child[c] = new Trie();
        }
        return child[c]->insert(word, ++pos);
    }

    bool search(string &word, int pos) {
        if(pos==(int)word.length()) return ed;
        int c = (int)(word[pos] - '0');
        if(child[c]==NULL) return false;
        return child[c]->search(word, ++pos);
    }
}*root;



int main()
{
    string keys[] = {"1", "12", "23", "26", "203", "07", "8", "077"};

    root = new Trie();

    for(int i=0; i<8; i++) {
        root->insert(keys[i], 0);
    }

    string str1 = "07", str2 = "0";

    cout << root->search(str1, 0) << endl; /// prints 1
    cout << root->search(str2, 0) << endl; /// prints 0

    return 0;
}
