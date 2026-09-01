class Solution {
public:
    int maxRepOpt1(string s) {
        map<char,int>mpp;
        for(char c : s) mpp[c]++;
        int ans = -1, n=s.size();
        for(char ch='a'; ch<='z'; ch++){
            int diff=0,l=0;
            for(int i=0;i<n;i++){
                if(s[i] != ch){
                    diff++;
                }
                while(diff > 1){
                    if(s[l] != ch) diff--;
                    l++;
                }
                ans = max(ans,min(i-l+1,mpp[ch]));
            }
        }
        return ans;
    }
};