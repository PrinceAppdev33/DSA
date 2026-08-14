class Solution {
public:
    int totalFruit(vector<int>& a) {
        map<int,int>mpp;
        int l=0,n=a.size(),ans=0;
        for(int i=0;i<n;i++){
            mpp[a[i]]++;
            while(mpp.size() > 2){
                mpp[a[l]]--;
                if(mpp[a[l]] == 0)
                    mpp.erase(a[l]);
                l++;
            }
            ans=max(ans,i-l+1);
        }
        return ans;
    }
};