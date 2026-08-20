/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        if (root->val == key) {
    if (!root->left) return root->right;
    if (!root->right) return root->left;

    TreeNode* lft = root->left;
    while (lft->right) lft = lft->right;

    lft->right = root->right;
    return root->left;
}
        TreeNode* cur = root;
        TreeNode* prev = root;
        if(key > cur->val) cur = cur->right;
        else cur = cur->left;
        while(true){
            if(!cur) return root;
            if(cur->val == key){
                break;
            }
            if(key > cur->val){
                prev = cur;
                cur = cur->right;
            } 
            else{
                prev = cur;
                cur = cur->left;
            } 
        }
        if(cur->left){
            TreeNode* lft = cur->left;
            while(lft->right) lft = lft->right;
            lft->right = cur->right;
            if(prev->val > cur->val){
                prev->left = cur->left;
            } else{
                prev->right = cur->left;
            }
            cur->right = NULL;
            cur->left = NULL;
        } else{
            if(prev->val > cur->val){
                prev->left = cur->right;
            } else{
                prev->right = cur->right;
            }
            cur->right = NULL;
            cur->left = NULL;
        }
        return root;
    }
};