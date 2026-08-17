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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,int>>q;
        if(!root) return 0;
        q.push({root,0});
        long long ans=0;
        while(!q.empty()){
            int size = q.size();
            long long mmin = 0;
            long long first,last;
            for(int i=0;i<size;i++){
                long long curid = q.front().second - mmin;
                TreeNode* node = q.front().first;
                q.pop();
                if(i == 0) first = curid;
                if(i == size-1) last = curid;
                if(node->left) q.push({node->left,2*curid+1});
                if(node->right) q.push({node->right,2*curid+2});
            }
            ans = max(ans,last-first+1);
        }
        return ans;
    }
};