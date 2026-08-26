class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        int p = t.size();
        if(n!=p) return false;
        int b[123] = {0};
        int c[123] = {0};
        for(int i=0;i<n;i++){
            b[s[i]]++;
            c[t[i]]++;
        }
       
        for(int i=97;i<=122;i++){
            if(b[i]!=c[i]){
                return false;
            }
        }
        return true;

        
    }
};