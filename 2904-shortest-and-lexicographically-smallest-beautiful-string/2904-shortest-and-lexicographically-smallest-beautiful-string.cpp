class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        string ans;
        for(int i=0;i<n;i++){
            int cnt=0;
            string cur = "";
            for(int j=i;j<n;j++){
                cur += s[j];
                if(s[j]=='1') cnt++;
                if(cnt>k) break;
                if(cnt == k){
                    if(ans =="" || cur.size() < ans.size() || (cur.size()==ans.size() && cur < ans)) ans = cur;
                }
            }
        }
        return ans;
    }
};