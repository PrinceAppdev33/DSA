class Solution {
public:
    int minimumFlips(int n) {
        string ans;
        int c=0;
        while(n>0){
            if(n%2==0) ans += '0';
            else ans += '1';
            n = n/2;
        }
        for(int i=0;i<ans.size()/2;i++){
            if(ans[i] != ans[ans.size()-i-1]) c++;
        }
        return 2*c;
    }
};