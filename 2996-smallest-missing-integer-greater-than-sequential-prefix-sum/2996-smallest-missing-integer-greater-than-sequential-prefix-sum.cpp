class Solution {
public:
    int missingInteger(vector<int>& a) {
        map<int,int>mpp;
        for(int x : a) mpp[x]++;
        int p=0,sum=a[0];
        for(int i=1;i<a.size();i++){
            if(a[i] != a[i-1]+1){
                p = a[i-1];
                break;
            }
            sum+=a[i];
        }
        while(true){
            if(!mpp[sum]) return sum;
            sum++;
        }
    }
};