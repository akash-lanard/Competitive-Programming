#include <bits/stdc++.h>
using namespace std;

#define Set(N,p) N=((N)|((1LL)<<(p)))
#define Reset(N,p) N=((N)&(~((1LL)<<(p))))
#define Check(N,p) (!(((N)&((1LL)<<(p)))==(0)))

#define LL long long

/// Assumed int size
#define MX 32

/// A Trie Node
struct Node {
    long long val; /// val is used only in the leave nodes
    Node *child[2];
    Node() {
        val = 0;
        child[0] = child[1] = NULL;
    }
} *root;

void Delete(Node *curr) {
    for(int i=0; i<2; i++) {
        if(curr->child[i]) {
            Delete(curr->child[i]);
        }
    }
    delete (curr);
}

/// Inserts prefix_xor to trie with given root
void Insert(LL prefix_xor) {
    Node *curr = root;
                                 /// Start from the msb, insert all bits of
    for(int i=MX-1; i>=0; i--) { /// prefix_xor into Trie

        int id = Check(prefix_xor, i); /// Find current bit in given prefix
        if(curr->child[id]==NULL) {
            curr->child[id] = new Node(); /// Create a new node if needed
        }
        curr = curr->child[id];
    }
    curr->val = prefix_xor; /// store value at the leaf node
}

/// Finds the maximum XOR ending with last number in
/// prefix XOR 'pre_xor' and returns the XOR of this maximum
/// with pre_xor which is maximum XOR ending with last element
/// of pre_xor.
LL Query(LL prefix_xor) {
    Node *curr = root;

    for(int i=MX-1; i>=0; i--) {
        int id = Check(prefix_xor, i);   /// Find current bit in given prefix

        if(curr->child[1-id]!=NULL) {    /// Traverse Trie, first look for a
            curr = curr->child[1-id];    /// prefix that has opposite bit
        }
        else if(curr->child[id]!=NULL) { /// If there is no prefix with opposite
            curr = curr->child[id];      /// bit, then look for same bit.
        }
    }
    return prefix_xor^(curr->val);
}

int main () {
    int tc;
    cin >> tc;
    for(int i=0; i<tc; i++) {
        root = new Node();
        Insert(0);

        int n;
        cin >> n;

        LL ret = 0, prefix_xor = 0;
        for(int j=0; j<n; j++) {
            long long a;
            cin >> a;
            prefix_xor ^= a;
            Insert(prefix_xor);
            ret = max(ret, Query(prefix_xor));
        }

        cout << ret << "\n";

        Delete(root);
    }

    return 0;
}
