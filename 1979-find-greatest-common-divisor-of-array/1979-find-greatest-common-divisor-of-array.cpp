class Solution {
public:
    int findGCD(vector<int>& a) {
        sort(a.begin(),a.end());
        return gcd(a[a.size()-1],a[0]);
    }
};