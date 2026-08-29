class Solution {
public:
    long long maxSum(vector<int>& a, int m, int k) {
        map<int,int>mpp;
        long long sum=0, ans=0, left=0;
        for(int i=0;i<a.size();i++){
            sum += a[i];
            mpp[a[i]]++;
            if(i - left + 1 > k){
                sum -= a[left];
                mpp[a[left]]--;
                if(mpp[a[left]] == 0) mpp.erase(a[left]);
                left++;
            }
            if(i-left+1 == k && mpp.size() >= m) ans = max(ans,sum);

        }
        return ans;
    }
};