class Solution {
public:
    int maximumValue(vector<string>& s) {
        int ans = 0;

        for (string str : s) {
            bool isNum = true;

            for (char c : str) {
                if (!isdigit(c)) {
                    isNum = false;
                    break;
                }
            }

            if (isNum)
                ans = max(ans, stoi(str));
            else
                ans = max(ans, (int)str.size());
        }

        return ans;
    }
};