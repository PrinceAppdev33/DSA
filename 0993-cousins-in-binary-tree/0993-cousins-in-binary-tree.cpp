class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int n = q.size();
            bool foundX = false, foundY = false;

            while (n--) {
                TreeNode* node = q.front();
                q.pop();

                if (node->val == x) foundX = true;
                if (node->val == y) foundY = true;

                // Same parent => not cousins
                if (node->left && node->right) {
                    if ((node->left->val == x && node->right->val == y) ||
                        (node->left->val == y && node->right->val == x)) {
                        return false;
                    }
                }

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            // Both found at same level and weren't siblings
            if (foundX && foundY) return true;

            // Only one found => different depths
            if (foundX || foundY) return false;
        }

        return false;
    }
};