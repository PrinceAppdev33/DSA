class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        int n = s1.size(),a=0,b=0;
        for(int i=0;i<n;i++){
            if(s2[i] < s1[i]) a++;
            if(s1[i] < s2[i]) b++;
        }
        if(a==0 || b==0) return 1;
        return 0;
    }
};