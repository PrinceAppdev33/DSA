class Solution {
public:
    int alternateDigitSum(int n) {
        int c=0;
        int x=n;
        while(x>0){
            x = x/10;
            c++;
        }
        bool p = false;
        int ans=0;
        if(c%2==0) p = true;
        else p = false;
        while(n>0){
            int y = n%10;
            if(p) y = -y;
            ans += y;
            p = !p;
            n = n/10;
        }
        return ans;
    }
};