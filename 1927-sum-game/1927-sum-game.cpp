class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int sumL = 0, sumR = 0;
        int qL = 0, qR = 0;

        for (int i = 0; i < n; i++) {
            if (i < n / 2) {
                if (num[i] == '?')
                    qL++;
                else
                    sumL += num[i] - '0';
            } else {
                if (num[i] == '?')
                    qR++;
                else
                    sumR += num[i] - '0';
            }
        }

        // Case 1: string only contains digits
        if (qL + qR == 0)
            return sumL != sumR;

        // Case 2: odd number of '?'
        if ((qL + qR) % 2)
            return true;

        // Case 3a: same number of '?' on both sides
        if (qL == qR)
            return sumL != sumR;

        // Case 3b
        return 2 * (sumL - sumR) != 9 * (qR - qL);
    }
};