class Solution {
public:
    int minimumLength(string s) {
        map<char,int>mpp;
        int ans=0;
        for(char c : s) mpp[c]++;
        for(auto it : mpp){
            if(it.second > 2){
                if(it.second%2==0) ans += 2;
                else ans += 1;
            }
            else ans += it.second;
        }
        return ans;
    }
};