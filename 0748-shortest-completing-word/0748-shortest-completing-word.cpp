class Solution {
public:
    bool isAlpha(char ch) {
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
            return true;
        return false;
    }
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<int> freq(26, 0);
        int n = licensePlate.size();
        for (int i = 0; i < n; i++) {
            if (isAlpha(licensePlate[i])) {
                char ch = tolower(licensePlate[i]);
                freq[ch - 'a']++;
            }
        }
        string ans = "";
        int minLen = INT_MAX;
        for (int i = 0; i < words.size(); i++) {
            vector<int> tempFreq(26, 0);
            bool valid = true;
            for (int j = 0; j < words[i].size(); j++)
                tempFreq[words[i][j] - 'a']++;

            for (int k = 0; k < 26; k++) {
                if (freq[k] > tempFreq[k]) {
                    valid = false;
                    break;
                }
            }
            if (valid && minLen > words[i].size()) {
                ans = words[i];
                minLen = words[i].size();
            }
        }
        return ans;
    }
};