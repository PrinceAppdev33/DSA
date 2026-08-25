class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& q, vector<string>& w) {
        vector<int> v;

        // Calculate f(W) for every word
        for (int i = 0; i < w.size(); i++) {
            sort(w[i].begin(), w[i].end());

            char c = w[i][0];
            int cnt = 0;

            for (int k = 0; k < w[i].size(); k++) {
                if (w[i][k] == c)
                    cnt++;
                else
                    break;
            }

            v.push_back(cnt);
        }

        sort(v.begin(), v.end());

        vector<int> ans;

        // Calculate f(query)
        for (int i = 0; i < q.size(); i++) {
            sort(q[i].begin(), q[i].end());

            char c = q[i][0];  // FIXED: q[i], not w[i]
            int cnt = 0;

            for (int k = 0; k < q[i].size(); k++) {
                if (q[i][k] == c)
                    cnt++;
                else
                    break;
            }
            int pos = upper_bound(v.begin(), v.end(), cnt) - v.begin();

            ans.push_back(v.size() - pos);
        }

        return ans;
    }
};