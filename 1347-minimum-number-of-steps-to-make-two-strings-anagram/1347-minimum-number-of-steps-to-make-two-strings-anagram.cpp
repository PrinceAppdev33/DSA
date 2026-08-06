class Solution {
public:
    int minSteps(string s, string t) {
        map<char,int>m1,m2;
        for(char c : s) m1[c]++;
        for(char c : t) m2[c]++;
        int ans = 0;
        for(auto it : m1){
            if(m2.find(it.first) != m2.end()){
                ans += min(it.second,m2[it.first]);
            }
        }
        return s.size() - ans;
    }
};