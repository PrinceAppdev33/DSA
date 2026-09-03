class Solution {
public:
    int ladderLength(string bg, string end, vector<string>& w) {
        map<string,int>mpp,vis;
        for(int i=0;i<w.size();i++){
            mpp[w[i]]++;
        }
        queue<pair<string,int>>q;
        q.push({bg,1});
        vis[bg] = 1;
        while(!q.empty()){
            string cur = q.front().first;
            int cnt = q.front().second;
            q.pop();
            if(cur == end) return cnt;
            for(int i=0;i<cur.size();i++){
                for(char ch='a'; ch<='z'; ch++){
                    string ans = cur;
                    ans[i] = ch;
                    if(mpp.find(ans) != mpp.end() && vis[ans]<1){
                        vis[ans] = 1;
                        q.push({ans,cnt+1});
                    }
                }
            }  
        }
        return 0;
        
    }
};