class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>vis(n,-1);
        stack<int>q;
        for(int i=0; i<n; i++){
            if(vis[i] != -1) continue;
            vis[i] = 1;
            q.push(i);
            while(!q.empty()){
                int node = q.top();
                q.pop();
                for(int x : graph[node]){
                    if(vis[x] == vis[node]) return false;
                    if(vis[x] == -1){
                        vis[x] = 1 - vis[node];
                        q.push(x);
                    }
                }
            }
        }
        return true;
    }
};