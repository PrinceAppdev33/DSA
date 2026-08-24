class Solution {
public:
    string addStrings(string a, string b) {
        int n = a.size(), m= b.size();
        int i=n-1,j=m-1, c=0;
        string ans;
        while(i>=0 && j>=0){
            int sum = a[i]-'0' + b[j]-'0' + c;
            if(sum>9){
                c = 1;
                sum = sum%10;
            } 
            else c = 0;
            ans += to_string(sum);
        i--;
        j--;
    }
    while (i >= 0) {

            int sum = (a[i] - '0') + c;

            if (sum > 9) {

                c = 1;

                sum %= 10;

            } else {

                c = 0;

            }

            ans += to_string(sum);

            i--;

        }

        while (j >= 0) {

            int sum = (b[j] - '0') + c;

            if (sum > 9) {

                c = 1;

                sum %= 10;

            } else {

                c = 0;

            }

            ans += to_string(sum);

            j--;

        }
            if(c>0) ans += to_string(c);

    reverse(ans.begin(), ans.end());
    return ans;
    }
};