class Solution {
public:
    int findLHS(vector<int>& a) {
        map<int,int>mpp;
        for(int x: a) mpp[x]++;
        int ans=0,z=0,prev=0,pre=0;
        for(auto it : mpp){
            if(z==0){
                prev = it.first;
                pre = it.second;
                z++;
            } else{
                if(it.first-1 == prev){
                    ans = max(ans, pre+it.second);
                }
                prev = it.first;
                pre = it.second;
            }
        }
        return ans;
    }
};