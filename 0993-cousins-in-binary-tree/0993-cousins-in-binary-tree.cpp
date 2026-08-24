class Solution {
public:
    void solve(TreeNode* root, int x, int dep, int &ansDep, int &parent) {
        if (!root) return;

        if (root->left && root->left->val == x) {
            ansDep = dep + 1;
            parent = root->val;
            return;
        }

        if (root->right && root->right->val == x) {
            ansDep = dep + 1;
            parent = root->val;
            return;
        }

        solve(root->left, x, dep + 1, ansDep, parent);
        solve(root->right, x, dep + 1, ansDep, parent);
    }

    bool isCousins(TreeNode* root, int x, int y) {
        int dep1 = -1, dep2 = -1;
        int parent1 = -1, parent2 = -1;

        solve(root, x, 0, dep1, parent1);
        solve(root, y, 0, dep2, parent2);

        return dep1 == dep2 && parent1 != parent2;
    }
};