class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        int n = s.size(), m = t.size();
        vector<int>v(26,0);
        if(n != m) return 0;
        for(int i=0;i<n;i++){
            int diff = (t[i]-s[i]+26)%26;
            if(diff == 0) continue;
            if(diff + 26*v[diff] > k) return 0;
            v[diff]++;
        }
        return 1;
    }
};