class Solution {
public:
    int ladderLength(string bg, string end, vector<string>& w) {
        queue<pair<string,int>>q;
        map<string,int>mpp;
        int n = w.size();
        for(int i=0;i<n;i++) mpp[w[i]] = 1;
        q.push({bg,1});
        while(!q.empty()){
            string cur = q.front().first;
            int cnt = q.front().second;
            q.pop();
            if(cur == end) return cnt;
            for(int i=0;i<cur.size();i++){
                for(char ch = 'a'; ch<='z';ch++){
                    if(ch == cur[i]) continue;
                    string op = cur;
                    op[i] = ch;
                    if(mpp.find(op) != mpp.end() && mpp[op]==1){
                        q.push({op,cnt+1});
                        mpp[op] = 2;
                    } 
                }
            }
        }
        return 0;
    }
};