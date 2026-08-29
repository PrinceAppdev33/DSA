class Solution {
public:
    int countLargestGroup(int n) {
        map<int,int>mpp;
        int count=0,ans=-1;
        for(int i=1;i<=n;i++){
            int sum=0;
            int x = i;
            while(x>0){
                sum += x%10;
                x = x/10;
            }
            mpp[sum]++;
            ans = max(ans,mpp[sum]);
        }
        for (auto& p : mpp) if (p.second == ans) ++count;
        return count;

    }
};