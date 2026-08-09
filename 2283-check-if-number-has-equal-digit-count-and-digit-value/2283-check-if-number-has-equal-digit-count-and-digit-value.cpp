class Solution {
public:
    bool digitCount(string a) {
        map<int,int>mpp;
        for(char c : a) mpp[c-'0']++;
        for(int c=0;c<a.size();c++){
            if((a[c]-'0') != mpp[c]) return 0;
        }
        return 1;
    }
};