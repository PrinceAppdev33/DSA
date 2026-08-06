class Solution {
public:
    int smallestNumber(int n, int t) {
        for(int i=n;i<=(n+10);i++){
            int prod = 1;
            int p = i;
            while(p>0){
                prod *= p%10;
                p = p/10;
            }
            if(prod%t==0) return i;
        }
        return 0;
    }
};