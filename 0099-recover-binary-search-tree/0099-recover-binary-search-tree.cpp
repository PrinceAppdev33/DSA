class Solution {
public:
    void inorder(TreeNode* root, vector<int>& v){
        if(root == NULL) return;

        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
    }

    void update(TreeNode* root, vector<int>& v, int& i){
        if(root == NULL) return;

        update(root->left, v, i);

        root->val = v[i++];
        
        update(root->right, v, i);
    }

    void recoverTree(TreeNode* root) {
        vector<int> in;

        inorder(root, in);

        sort(in.begin(), in.end());

        int i = 0;
        update(root, in, i);
    }
};