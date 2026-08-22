class Solution {
public:
    bool checkDivisibility(int n) {
        int p = n,ans=0,prod=1;
        while(p>0){
            ans += p%10;
            prod *= p%10;
            p /= 10;
        }
        return (n%(ans+prod)==0);
    }
};