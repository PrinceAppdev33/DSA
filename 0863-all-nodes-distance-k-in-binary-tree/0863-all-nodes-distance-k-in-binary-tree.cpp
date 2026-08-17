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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*,TreeNode*>mpp;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left){
                    q.push(node->left);
                    mpp[node->left] = node;
                } 
                if(node->right){
                    q.push(node->right);
                    mpp[node->right] = node;
                } 
            }
        }

        int dist = 0;
        queue<TreeNode*>qp;
        qp.push(target);
        map<TreeNode*,bool>vis;
        vis[target] = true;
        vector<int>ans;
        while(!qp.empty()){
            int size = qp.size();
            if(dist == k){
                while(size--){
                    ans.push_back(qp.front()->val);
                    qp.pop();
                }
                return ans;
            }
            for(int i=0;i<size;i++){
                TreeNode* node = qp.front();
                qp.pop();
                if(mpp.count(node) && !vis[mpp[node]]){
                    qp.push(mpp[node]);
                    vis[mpp[node]] = true;
                } 
                if(node->left && !vis[node->left]){
                    qp.push(node->left);
                    vis[node->left] = true;
                } 
                if(node->right && !vis[node->right]){
                    qp.push(node->right);
                    vis[node->right] = true;
                } 
            }
            dist++;
        }
        return ans;
    }
};