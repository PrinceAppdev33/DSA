class Solution {
public:
    vector<int> resultArray(vector<int>& arr) {
        vector<int>a,b;
        int ax=arr[0],bx=arr[1],n=arr.size();
        for(int i=0;i<n;i++){
            if(i < 2){
                if(i%2==0) a.push_back(arr[i]);
                else b.push_back(arr[i]);
            } else{
                if(ax > bx){
                    a.push_back(arr[i]);
                    ax = arr[i];
                } else{
                    b.push_back(arr[i]);
                    bx = arr[i];
                }
            }
        }
        vector<int>ans;
        for(int x : a) ans.push_back(x);
        for(int x : b) ans.push_back(x);
        return ans;
    }
};