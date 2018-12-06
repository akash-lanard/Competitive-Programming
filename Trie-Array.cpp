#include <bits/stdc++.h>
using namespace std;

#define SIZE 100000

/// Trie Array Based Implementation
/// Call insert() to insert new string
/// Call search() to search a string

struct node {
    int cnt; /// Change here if you need
    int child[55];
};

node T[SIZE];

struct Trie {
    int id;

    void createNode() {
        T[id].cnt = 0;
        memset(T[id].child, -1, sizeof(T[id].child));
        id++;
    }

    void clear() {
        id = 0;
        createNode();
    }

    /// Returns the corresponding integer id of the character
    int FID(const char &c) {
        if(c>='A' && c<='Z') return c - 'A';
        else return (c - 'a') + 26;
    }

    void insert(string &s) {
        int cur = 0;
        T[cur].cnt++;
        for(int i=0; i<s.size(); i++) {
            int p = FID(s[i]);
            if(T[cur].child[p]==-1) {
                T[cur].child[p] = id;
                createNode();
            }
            cur = T[cur].child[p];
            T[cur].cnt++;
        }
    }

    /// Returns number of occurance of s.
    int search(string &s) {
        int cur = 0;
        for(int i=0; i<s.size(); i++) {
            int p = FID(s[i]);
            if(T[cur].child[p]==-1) return 0;
            cur = T[cur].child[p];
        }
        return T[cur].cnt;
    }
}root;

int main()
{
    string keys[] = {"the", "a", "there",
                    "answer", "any", "by",
                     "bye", "their" };

    root.clear();

    for(int i=0; i<8; i++) {
        root.insert(keys[i]);
    }

    string str1 = "the", str2 = "these"; //prints 3 and 0

    cout << root.search(str1) << endl;
    cout << root.search(str2) << endl;

    return 0;
}
