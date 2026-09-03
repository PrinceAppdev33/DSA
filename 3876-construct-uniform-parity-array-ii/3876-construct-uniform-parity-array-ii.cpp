class Solution {
public:
    bool uniformArray(vector<int>& a) {
        int c=0;
        sort(a.begin(),a.end());
        for(int x : a){
            if(x%2==1) c++;
        }
        if(c>0){
            int k=0;
            for(int x : a){
                if(x%2==0){
                    if(k==0) return 0;
                }
                else k++;
            }
            return 1;
        }
        else return 1;
    }
};