class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& a, vector<vector<int>>& vis){
        vis[i][j] = 1;
        int n = a.size();
        int m = a[0].size();
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        for(int k=0;k<4;k++){
            int negr = i + dr[k];
            int negc = j + dc[k];
            if(negr >=0 && negr <n && negc >=0 && negc <m && vis[negr][negc]==0 && a[negr][negc]=='O'){
                dfs(negr,negc,a,vis);
            }
        }
    }
    void solve(vector<vector<char>>& a) {
        int n = a.size();
        int m = a[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0 || i==n-1 || j==0 || j==m-1) && a[i][j]=='O' && vis[i][j]==0){
                    dfs(i,j,a,vis);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 && a[i][j]=='O') a[i][j] = 'X';
            }
        }
        

    }
};