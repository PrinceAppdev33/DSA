class Solution {
public:
    vector<long long> getDistances(vector<int>& a) {
        map<int, vector<int>> mpp;
        int n = a.size();

        for(int i = 0; i < n; i++) {
            mpp[a[i]].push_back(i);
        }

        vector<long long> res(n);

        for(auto it : mpp) {
            vector<int> p = it.second;

            vector<long long> pre(p.size() + 1, 0);

            for(int i = 0; i < p.size(); i++) {
                pre[i + 1] = pre[i] + (long long)p[i];
            }

            for(int i = 0; i < p.size(); i++) {
                long long left =
                    (long long)p[i] * (i + 1) - pre[i + 1];

                long long right =
                    (pre[p.size()] - pre[i])
                    - (long long)p[i] * (p.size() - i);

                res[p[i]] = left + right;
            }
        }

        return res;
    }
};