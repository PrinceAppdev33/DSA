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
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int lh = leftheight(root);
        int rg = rightheight(root);

        if(lh == rg) return (1 << lh) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
    int leftheight(TreeNode* root){
        int cnt = 1;
        while(root->left){
            root = root->left;
            cnt++;
        }
        return cnt;
    }
    int rightheight(TreeNode* root){
        int cnt = 1;
        while(root->right){
            root = root->right;
            cnt++;
        }
        return cnt;
    }
};