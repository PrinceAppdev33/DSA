class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* cur = root;

        while (cur) {
            if (cur->left == NULL) {
                ans.push_back(cur->val);
                cur = cur->right;
            }
            else {
                TreeNode* prev = cur->left;

                while (prev->right != NULL && prev->right != cur) {
                    prev = prev->right;
                }

                if (prev->right == NULL) {
                    // Visit root before going to left subtree
                    ans.push_back(cur->val);

                    // Create thread
                    prev->right = cur;
                    cur = cur->left;
                }
                else {
                    // Remove thread
                    prev->right = NULL;
                    cur = cur->right;
                }
            }
        }

        return ans;
    }
};