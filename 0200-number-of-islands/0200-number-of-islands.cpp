class Solution {
public:
    void dfs(int x, int y, vector<vector<char>>& arr, vector<vector<int>>& vis){
        int n = arr.size(), m= arr[0].size();
        queue<pair<int,int>>q;
        q.push({x,y});
        vis[x][y] = 1;
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            if(i>0 && arr[i-1][j]=='1' && !vis[i-1][j]){
                q.push({i-1,j});
                vis[i-1][j] = 1;
            } 
            if(j>0 && arr[i][j-1]=='1' && !vis[i][j-1]){
                q.push({i,j-1});
                vis[i][j-1] = 1;
            } 
            if(j<m-1 && arr[i][j+1]=='1' && !vis[i][j+1]){
                q.push({i,j+1});
                vis[i][j+1] = 1;
            } 
            if(i<n-1 && arr[i+1][j]=='1' && !vis[i+1][j]){
                q.push({i+1,j});
                vis[i+1][j] = 1;
            } 
        }
    }
    int numIslands(vector<vector<char>>& arr) {
        int n = arr.size(), m= arr[0].size(), cnt=0;
        vector<vector<int>>vis(n, vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j] == '1' && !vis[i][j]){
                    cnt++;
                    dfs(i,j,arr,vis);
                }
            }
        }
        return cnt;
    }
};