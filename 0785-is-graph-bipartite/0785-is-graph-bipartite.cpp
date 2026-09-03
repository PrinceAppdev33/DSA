class Solution {
public:
    bool isBipartite(vector<vector<int>>& a) {
        map<int, int> mp1, mp2;
        int n = a.size();
        vector<int> vis(n, 0);
        for(int i=0;i<n;i++){
            if(vis[i]==1) continue;
            stack<int>s1,s2;
            
                s1.push(i);
            mp1[i]++;
            vis[i] = 1;
            
            
            while(!s1.empty() || !s2.empty()){
                if(!s1.empty()){
                    int node = s1.top();
                    s1.pop();
                    for(int x : a[node]){
                        if(!vis[x]){
                        mp2[x]++;
                        s2.push(x);
                        vis[x] = 1;
                        }
                    }
                }
                if(!s2.empty()){
                    int node = s2.top();
                    s2.pop();
                    for(int x : a[node]){
                        if(!vis[x]){
                        mp1[x]++;
                        s1.push(x);
                        vis[x] = 1;
                        }
                    }
                }
            }
        }
        for(auto it : mp1){
            int x = it.first;
            for(int p : a[x]){
                if(mp1.find(p) != mp1.end()) return false;
            }
        }
        for(auto it : mp2){
            int x = it.first;
            for(int p : a[x]){
                if(mp2.find(p) != mp2.end()) return false;
            }
        }
        return true;
    }
};