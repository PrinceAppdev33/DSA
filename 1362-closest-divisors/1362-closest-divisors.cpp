class Solution {
public:
    vector<int> closestDivisors(int num) {
        set<pair<int,int>>st;
        for(int i=1; i<=sqrt(num+1); i++){
            if((num+1)%i==0){
                int mn = min(i,(num+1)/i);
                int mx = max(i,(num+1)/i);
                st.insert({mn,mx});
            }
        }
        for(int i=1; i<=sqrt(num+2); i++){
            if((num+2)%i==0){
                int mn = min(i,(num+2)/i);
                int mx = max(i,(num+2)/i);
                st.insert({mn,mx});
            }
        }
        int maxi = INT_MAX;
        int p,q;
        for(auto it : st){
            int a = it.first;
            int b = it.second;
            if(abs(a-b) < maxi){
                p = a;
                q = b;
                maxi = abs(a-b);
            }
        }
        return {p,q};
    }
};