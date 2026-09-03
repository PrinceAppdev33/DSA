class Solution {
public:
    vector<int> findOriginalArray(vector<int>& a) {
        int n = a.size();
        sort(a.begin(), a.end());
        if (n == 1)
            return {};
        map<int, int> mpp;
        vector<int> vis(n, -1);
        int c = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == 0)
                c++;
            mpp[a[i]]++;
        }
        vector<int> v;
        if (c == n) {
            c = c / 2;
            while (c--)
                v.push_back(0);
            return v;
        }

        for (auto it : mpp) {
            int x = it.first;
            while (mpp[x]>0) {
                if (mpp[2*x]>0) {
                    if(x==0 && mpp[x] <2) return {};
                    v.push_back(x); 
                    mpp[2 * x]--;
                    mpp[x]--;
                } else return {};
            }
        }
        return v;
    }
};