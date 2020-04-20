/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-s20-hw8/challenges/binary-tree-4/submissions/code/1322536174
 * Title: hw8_1
 * Abstract: Provides a few functions for a binary tree
 * Author: Albert Salas
 * ID: 7777
 * Date: 04/07/2020
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node {
    // Data part for a node.
    int data;
    Node *left;
    Node *right;

    // Constructor for a new node.
    explicit Node(int d) {
        data = d;
        left = nullptr;
        right = nullptr;
    }
};

void append(Node **root, int value) {
    if (*root == nullptr) {
        Node *n = new Node(value);
        *root = n;
        return;
    }
    queue<Node *> q;
    q.push(*root);
    Node *newNode = new Node(value);
    while (!q.empty()) {
        Node *node = q.front();
        q.pop();
        if (node->left == nullptr) {
            node->left = newNode;
            return;
        } else if (node->right == nullptr) {
            node->right = newNode;
            return;
        } else {
            q.push(node->left);
            q.push(node->right);
        }
    }
}

void preOrder(Node *root) {
    if (root == nullptr) {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

int height(Node *root) {
    if (root == nullptr) {
        return -1;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    int height = max(leftHeight, rightHeight);
    return height + 1;
}

void levelOrder(Node *root) {
    if (root == nullptr) {
        return;
    }
    queue<Node *> q;
    q.push(root);
    while (!q.empty()) {
        Node *node = q.front();
        q.pop();
        cout << node->data << " ";
        if (node->left != nullptr) {
            q.push(node->left);
        }
        if (node->right != nullptr) {
            q.push(node->right);
        }
    }
    cout << endl;
}

void deleteLastNode(Node **root) {
    if (root == nullptr) {
        return;
    }
    queue<Node *> q;
    q.push(*root);
    vector<Node *> v;
    while (!q.empty()) {
        Node *node = q.front();
        q.pop();
        v.push_back(node);
        if (node->left != nullptr) {
            q.push(node->left);
        }
        if (node->right != nullptr) {
            q.push(node->right);
        }
    }
    if (v.size() <= 1) {
        *root = nullptr;
        return;
    }
    unsigned int parentIndex = (v.size() - 2) / 2;
    Node *parentNode = v[parentIndex];
    Node *nodeToDelete = v[v.size() - 1];
    if (parentNode->left == nodeToDelete) {
        parentNode->left = nullptr;
    } else {
        parentNode->right = nullptr;

    }
}

void postOrder(Node *root) {
    if (root == nullptr) {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

void inOrder(Node *root, vector<int> &nums) {
    if (root == nullptr) {
        return;
    }
    inOrder(root->left, nums);
    nums.push_back(root->data);
    inOrder(root->right, nums);
}

bool isBST(Node *root) {
    if (root == nullptr) {
        return true;
    }
    vector<int> nums;
    inOrder(root, nums);
    if (nums.size() == 1) {
        return true;
    }
    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i - 1] > nums[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    int rootValue;
    cin >> rootValue;
    Node *root = new Node(rootValue);
    unsigned int numberOfOps;
    cin >> numberOfOps;
    cin.ignore();
    vector<string> ops(numberOfOps);
    for (int i = 0; i < numberOfOps; ++i) {
        string s;
        getline(cin, s);
        ops[i] = s;
    }

    for (const string &s : ops) {
        if (s.find("append") != string::npos) {
            int value = stoi(s.substr(6, s.size()));
            append(&root, value);
        } else if (s == "isBST") {
            if (isBST(root)) {
                cout << "true";
            } else {
                cout << "false";
            }
            cout << endl;
        } else if (s == "preOrder") {
            preOrder(root);
            cout << endl;
        } else if (s == "height") {
            cout << height(root) << endl;
        } else if (s == "levelOrder") {
            levelOrder(root);
        } else if (s == "deleteLastNode") {
            deleteLastNode(&root);
        } else if (s == "postOrder") {
            postOrder(root);
            cout << endl;
        } else if (s == "inOrder") {
            vector<int> nums;
            inOrder(root, nums);
            for (int i : nums) {
                cout << i << " ";
            }
            cout << endl;
        }
    }
    return 0;
}