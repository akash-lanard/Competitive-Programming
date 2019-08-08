#include <bits/stdc++.h>
using namespace std;


int mx = -1;

/// Trie Recursion based implementation
/// Create the root (root = new Trie())
/// Use insert and search accordingly
/// At the end call delete_trie() to delete all the nodes
/// Done for only digits by default

#define SIZE 26 ///change here

class Trie {
    bool ed;
    int cnt;
    Trie *child[SIZE];
    /// If ed is true, a word is finished here

public:
    Trie() {
        ed = false;
        cnt = 0;
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
        cnt++;

        if(pos==(int)word.length()) {
            ed = true;
            return;
        }
        int c = (int)(word[pos] - 'a'); ///change here
        if(child[c] == NULL) {
            child[c] = new Trie();
        }

        return child[c]->insert(word, ++pos);
    }

    bool search(string &word, int pos) {
        if(pos==(int)word.length()) return ed;
        int c = (int)(word[pos] - 'a'); ///change here
        if(child[c]==NULL) return false;
        return child[c]->search(word, ++pos);
    }

    int searchFreq(string &word, int pos) {
        if(pos==(int)word.length()) return cnt;
        int c = (int)(word[pos] - 'a'); ///change here
        if(child[c]==NULL) return 0;
        return child[c]->searchFreq(word, ++pos);
    }
}*root;


int main () {
    string keys[] = {"the", "a", "there",
                    "answer", "any", "by",
                     "bye", "their" };

    root = new Trie();

    for(int i=0; i<8; i++) {
        root->insert(keys[i], 0);
    }

    string str1 = "the", str2 = "these";

    cout << root->search(str1, 0) << endl; /// prints 1
    cout << root->search(str2, 0) << endl; /// prints 0

    cout << root->searchFreq(str1, 0) << endl; /// prints 3
    cout << root->searchFreq(str2, 0) << endl; /// prints 0

    return 0;
}

