class Solution {
public:
    bool isPossibleDivide(vector<int>& a, int k) {
        map<int, int> mpp;
        for (int x : a)
            mpp[x]++;
            int p = k;
        while (mpp.size()>0) {
            stack<int> st;
            int z=0;
            for (auto it : mpp) {
                z++;
                if (!st.empty()) {
                    if (it.first != st.top() + 1)
                        return 0;
                }
                st.push(it.first);
                mpp[it.first]--;
                if (mpp[it.first] == 0)
                    mpp.erase(it.first);
                if(z==k) break;
            }
            if(st.size()!=k) return 0;
        }
        return true;
    }
};