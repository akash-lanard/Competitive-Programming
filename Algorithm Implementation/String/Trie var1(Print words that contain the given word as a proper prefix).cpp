#include <bits/stdc++.h>
using namespace std;

/// Trie Recursion based implementation
/// Create the root (root = new Trie())
/// Use insert and search accordingly
/// At the end call delete_trie() to delete all the nodes
/// Done for only digits by default

#define SIZE 26

int flag;

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
        int c = (int)(word[pos] - 'a'); ///change here
        if(child[c] == NULL) {
            child[c] = new Trie();
        }
        return child[c]->insert(word, ++pos);
    }

    bool search(string &word, int pos) {
        if(pos==(int)word.length()) return ed;
        int c = (int)(word[pos] - 'a');
        if(child[c]==NULL) return false;
        return child[c]->search(word, ++pos);
    }

    void printWordsThatContainProperPrefix(string &word, int pos, string currStr) {
        if(pos<(int)word.length()) {
            int c = (int)(word[pos] - 'a');

            currStr += word[pos];

            if(child[c]==NULL) {
                return;
            }
            else {
                child[c]->printWordsThatContainProperPrefix(word, ++pos, currStr);
            }
        }
        else {
            if(ed && (pos!=(int)word.length())) {
                if(!flag) flag = 1;
                cout << currStr << "\n";
            }

            for(int i=0; i<SIZE; i++) {
                if(child[i]!=NULL) {
                    char currChar = (char)('a' + i);
                    string tempStr = currStr;
                    tempStr += currChar;
                    child[i]->printWordsThatContainProperPrefix(word, ++pos, tempStr);
                }
            }
        }
    }
}*root;

int main () {
    root = new Trie();

    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        string str;
        cin >> str;
        root->insert(str, 0);
    }

    int k;
    cin >> k;
    for(int i=0; i<k; i++) {
        string str;
        cin >> str;
        flag = 0;
        cout << "Case #" << i+1 << ":\n";
        root->printWordsThatContainProperPrefix(str, 0, "");
        if(!flag) {
            cout << "No match.\n";
        }
    }

    return 0;
}
