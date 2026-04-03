#include <iostream>
#include <string>
using namespace std;

struct Node {
    int key;
    Node *left;
    Node *right;
    Node *p;
    explicit Node(int k) : key(k), left(nullptr), right(nullptr), p(nullptr) {}
};

void transplant(Node *&root, Node *u, Node *v) {
    if (u->p == nullptr) {
        root = v;
    } else if (u == u->p->left) {
        u->p->left = v;
    } else {
        u->p->right = v;
    }
    if (v != nullptr) {
        v->p = u->p;
    }
}

Node *treeMinimum(Node *x) {
    while (x->left != nullptr) {
        x = x->left;
    }
    return x;
}

void treeInsert(Node *&root, Node *z) {
    Node *y = nullptr;
    Node *x = root;
    while (x != nullptr) {
        y = x;
        if (z->key < x->key) {
            x = x->left;
        } else {
            x = x->right;
        }
    }
    z->p = y;
    if (y == nullptr) {
        root = z;
    } else if (z->key < y->key) {
        y->left = z;
    } else {
        y->right = z;
    }
}

void treeDelete(Node *&root, Node *z) {
    if (z->left == nullptr) {
        transplant(root, z, z->right);
    } else if (z->right == nullptr) {
        transplant(root, z, z->left);
    } else {
        Node *y = treeMinimum(z->right);
        if (y->p != z) {
            transplant(root, y, y->right);
            y->right = z->right;
            y->right->p = y;
        }
        transplant(root, z, y);
        y->left = z->left;
        y->left->p = y;
    }
    delete z;
}

Node *treeSearch(Node *x, int k) {
    while (x != nullptr && k != x->key) {
        if (k < x->key) {
            x = x->left;
        } else {
            x = x->right;
        }
    }
    return x;
}

void inorderWalk(Node *x) {
    if (x != nullptr) {
        inorderWalk(x->left);
        cout << x->key << "\n";
        inorderWalk(x->right);
    }
}

void preorderWalk(Node *x) {
    if (x != nullptr) {
        cout << x->key << "\n";
        preorderWalk(x->left);
        preorderWalk(x->right);
    }
}

void postorderWalk(Node *x) {
    if (x != nullptr) {
        postorderWalk(x->left);
        postorderWalk(x->right);
        cout << x->key << "\n";
    }
}

int main() {
    Node *root = nullptr;
    string tok;
    while (cin >> tok) {
        if (tok == "e") {
            break;
        }
        if (tok == "oin") {
            inorderWalk(root);
            continue;
        }
        if (tok == "opre") {
            preorderWalk(root);
            continue;
        }
        if (tok == "opost") {
            postorderWalk(root);
            continue;
        }
        if (!tok.empty() && tok[0] == 'i') {
            int k;
            if (tok.size() > 1) {
                k = stoi(tok.substr(1));
            } else {
                cin >> k;
            }
            treeInsert(root, new Node(k));
            continue;
        }
        if (!tok.empty() && tok[0] == 'd') {
            int k;
            if (tok.size() > 1) {
                k = stoi(tok.substr(1));
            } else {
                cin >> k;
            }
            Node *z = treeSearch(root, k);
            if (z != nullptr) {
                treeDelete(root, z);
            }
        }
    }
    return 0;
}
