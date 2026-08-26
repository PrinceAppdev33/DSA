class Solution {
public:
    int getMinSwaps(string num, int k) {

        int n = num.size();

        // Store the copy of the string
        string res = num;

        // Find the K-th permutation
        for (int i = 0; i < k; i++) {
            next_permutation(num.begin(), num.end());
        }

        int swap_count = 0;

        // Convert res -> num using minimum adjacent swaps
        for(int i = 0; i < n; i++) {

            if(res[i] != num[i]) {

                int j = i + 1;

                // Find the correct digit
                while(res[i] != num[j]) {
                    j++;
                }

                // Bring it to position i using adjacent swaps
                while(j > i) {
                    swap(num[j], num[j - 1]);
                    swap_count++;
                    j--;
                }
            }
        }

        return swap_count;
    }
};