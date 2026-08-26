class Solution {
public:
    int scoreOfString(string s) {
        int sum=0;
        for(int i=1;i<s.size();i++){
            int x = s[i];
            int y = s[i-1];
            sum += abs(x-y);
        }
        return sum;
    }
};