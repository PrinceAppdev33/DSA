class Solution {
public:
    bool isSameAfterReversals(int num) {
        if(num ==0) return 1; 
        int x = num;
        int ans=0;
        while(x>0){
            ans = x%10;
            x = x/10;
        }
        if(ans == 0 || num%10== 0) return false;
        return 1;
    }
};