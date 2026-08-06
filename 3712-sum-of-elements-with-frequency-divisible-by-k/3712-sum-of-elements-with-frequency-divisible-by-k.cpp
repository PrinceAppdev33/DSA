class Solution {
public:
    int sumDivisibleByK(vector<int>& a, int k) {
        map<int,int>mpp;
        int ans=0;
        for(int x : a){
            mpp[x]++;
        }
        for(auto it : mpp){
            if(it.second%k==0) ans+= it.first*it.second;
        }
        return ans;
    }
};