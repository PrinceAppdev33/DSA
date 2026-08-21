class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& a) {
        int n = a.size(),m=a[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(j>0 && i>0){
                    if(a[i][j] != a[i-1][j-1]) return false;
                }
            }
        }
        return true;
    }
};