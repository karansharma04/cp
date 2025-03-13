#include<bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    int height;
    Node* parent;
    Node* left;
    Node* right;
    Node(int val) : val(val) , height(1) , parent(nullptr) , left(nullptr) , right(nullptr) {}
    Node(int val , Node* parent) : val(val) , height(1) , parent(parent) , left(nullptr) , right(nullptr) {}
};

class AVLTree {
public:
    AVLTree() : root(nullptr) {}
    void insert(int val) {
        if (!root) {
            root = new Node(val);
            return;
        }
        insert_rec(val , root , nullptr);
    }
    Node* insert_rec(int val , Node* root , Node* parent) {
        if (!root) {
            return new Node(val , parent);
        }
        if (val < root->val) {
            root->left = insert_rec(val , root->left , root);
        }
        else if (val > root->val) {
            root->right = insert_rec(val , root->right , root);
        }
        int left_height = root->left ? root->left->height : 0;
        int right_height = root->right ? root->right->height : 0;
        root->height = max(left_height , right_height) + 1;
        if (abs(left_height - right_height) > 1) {
            return balance(root);
        }
        return root;
    }
    Node* balance(Node* curr) {
        cout << curr->val << endl;
        cout << "hello 0" << endl;
        int left_height = 0 , right_height = 0;
        if (curr->left) left_height = curr->left->height;
        cout << "hello 0 1" << endl;
        if (curr->right) right_height = curr->right->height;
        cout << "hello 0 2" << endl;
        if (left_height > right_height) {
            cout << "hello 1" << endl;
            int child_left_height = 0 , child_right_height = 0;
            if (curr->left->left) {
                child_left_height = curr->left->left->height;
            }
            cout << "hello 2" << endl;
            if (curr->left->right) {
                child_right_height = curr->left->right->height;
            }
            cout << "hello 3" << endl;
            // Left Left heavy
            if (child_left_height > child_right_height) {
                right_rotation(curr->left);
                return curr->parent;
            }
            cout << "hello 4" << endl;
            // Left Right heavy
            left_rotation(curr->left->right);
            right_rotation(curr->left);
            return curr->parent;
        }
        else {
            cout << "hello 5" << endl;
            int child_left_height = 0 , child_right_height = 0;
            if (curr->right->left) {
                child_left_height = curr->right->left->height;
            }
            cout << "hello 6" << endl;
            if (curr->right->right) {
                child_right_height = curr->right->right->height;
            }
            cout << "hello 7" << endl;
            // Right Right heavy
            if (child_left_height < child_right_height) {
                left_rotation(curr->right);
                return curr->parent;
            }
            cout << "hello 8" << endl;
            // Right Left heavy
            right_rotation(curr->right->left);
            left_rotation(curr->right);
            return curr->parent;
        }
    }
    void right_rotation(Node* curr) {
        curr->parent->left = nullptr;
        curr->right = curr->parent;
        curr->parent = curr->parent->parent;
        curr->parent->parent = curr;
    }
    void left_rotation(Node* curr) {
        curr->parent->right = nullptr;
        curr->left = curr->parent;
        curr->parent = curr->parent->parent;
        curr->parent->parent = curr;
    }
    bool search(int val) {
        return search_rec(val , root);
    }
    bool search_rec(int val , Node* root) {
        if (!root) {
            return false;
        }
        if (val < root->val) return search_rec(val , root->left);
        else if (val > root->val) return search_rec(val , root->right);
        return true;
    }
    void remove_element(int val) {
        if (!root) {
            return;
        }
        remove_rec(val , root);
    }
    Node* remove_rec(int val , Node* root) {
        if (!root) {
            return nullptr;
        }
        if (val < root->val) return remove_rec(val , root->left);
        else if (val > root->val) return remove_rec(val , root->right);
        return nullptr;
    }
private:
    Node* root;
};

int main() {
    AVLTree a;
    a.insert(4);
    a.insert(3);
    a.insert(2);
    a.insert(1);
    cout << a.search(2) << endl;
    cout << a.search(0) << endl;
    cout << a.search(4) << endl;
    cout << a.search(3) << endl;
    cout << a.search(5) << endl;
    return 0;
}