class Solution {
public:
    void dfs(int &i, vector<vector<int>>& a, vector<bool>&vis){
        int n = a.size();
        queue<int>q;
        q.push(i);
        vis[i] = true;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int k=0;k<n;k++){
                if(a[node][k] == 1 && !vis[k]){
                    q.push(k);
                    vis[k] = true;
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& a) {
        int n = a.size();
        vector<bool>vis(n+1,false);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,a,vis);
                cnt++;
            }
        }
        return cnt;
    }
};