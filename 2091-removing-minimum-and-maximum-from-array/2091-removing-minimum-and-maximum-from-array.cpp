class Solution {
public:
    int minimumDeletions(vector<int>& a) {
        int mx = -1e9, mn = 1e9;
        int l=-1, r=-1;
        int n = a.size();
        for(int i=0;i<n;i++){
            if(a[i] > mx){
                l = i;
                mx = a[i];
            }
            if(a[i] < mn){
                r= i;
                mn = a[i];
            }
        }
        int fst = max(l+1,r+1);
        int lst = n- min(l,r);
        int med = (l+1) + (n-r);
        int med2 = (n-l) + (r+1);
        int ans = min(med,med2);
        return min(fst,min(lst,ans));
    }
};