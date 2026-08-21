class Solution {
public:
    int alternatingSubarray(vector<int>& a) {
        int n = a.size(),ans=-1;
        bool p = true;
        for(int i=0;i<n;i++){
            p = true;
            for(int j=i;j<n-1;j++){
                if(p){
                    if(a[j+1]-a[j] == 1){
                        ans = max(ans,j-i+2);
                        p = !p;
                    } else{
                        break;
                    }
                } else{
                    if(a[j+1]-a[j] == -1){
                        ans = max(ans,j-i+2);
                        p = !p;
                    } 
                    else break;
                }
                
            }
        }
        return ans;
    }
};