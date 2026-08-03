/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    bool solve(TreeNode* root, TreeNode* x,vector<TreeNode*>&ans){
        if(root == nullptr) return false;
        ans.push_back(root);
        if(root == x) return true;
        if(solve(root->left,x,ans) || solve(root->right,x,ans)) return true;
        ans.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==p || root==q) return root;
        vector<TreeNode*>p1,p2;
        solve(root,p,p1);
        solve(root,q,p2);
        TreeNode* op;
        for(int i=0;i<min(p1.size(),p2.size());i++){
            if(p1[i] == p2[i]) op = p1[i];
            else break;
        }
        return op;
    }
};