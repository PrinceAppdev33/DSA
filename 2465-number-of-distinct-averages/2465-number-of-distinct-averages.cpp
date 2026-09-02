class Solution {
public:
    int distinctAverages(vector<int>& a) {
        sort(a.begin(),a.end());
        set<double>st;
        int n = a.size();
        for(int i=0;i<n/2;i++){
            double avg = (a[i]+a[n-i-1])/2.0;
            st.insert(avg);
        }
        return st.size();
    }
};