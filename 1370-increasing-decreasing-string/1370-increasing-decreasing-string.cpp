class Solution {
public:
    string sortString(string s) {
        map<char,int>mpp;
        for(char c: s) mpp[c]++;
        string ans;
        while(mpp.size()>0){
            bool p = false;
            for(auto it : mpp){
                if(mpp[it.first]>0){
                    ans += it.first;
                    mpp[it.first]--;
                    p = true;
                }
            }
            string cur;
            for(auto it : mpp){
                if(mpp[it.first]>0){
                    cur += it.first;
                    mpp[it.first]--;
                    p = true;
                }
            }
            if(!p) break;
            reverse(cur.begin(),cur.end());
            ans+=cur;
        }
        return ans;
    }
};