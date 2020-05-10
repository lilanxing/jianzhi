#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;

    TreeNode(int _val) : val(_val), left(nullptr), right(nullptr) {}
};

void PrintPath(const std::vector<int>& path) {
    std::vector<int>::const_iterator iter = path.begin();
    while (iter != path.end()) {
        std::cout << *iter++ << " ";
    }
    std::cout << std::endl;
}

void FindPath(TreeNode* root, int sum, std::vector<int>& path, int cur) {
    if (root == nullptr) return;

    cur += root->val;
    path.push_back(root->val);

    bool is_leaf = root->left == nullptr && root->right == nullptr;
    if (is_leaf && cur == sum) {
        PrintPath(path);
    }

    if (root->left != nullptr) FindPath(root->left, sum, path, cur);
    if (root->right != nullptr) FindPath(root->right, sum, path, cur);

    path.pop_back();
}

void FindPath(TreeNode* root, int sum) {
    if (root == nullptr) return;
    std::vector<int> path;
    FindPath(root, sum, path, 0);
}

int main() {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(12);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(7);

    FindPath(root, 22);
}
