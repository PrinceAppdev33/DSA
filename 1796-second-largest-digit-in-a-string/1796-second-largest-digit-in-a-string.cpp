class Solution {
public:
    int secondHighest(string s) {
        int fst=-1, scd=-1;
        for(char c : s){
            if(isdigit(c)){
                int d = c - '0';
                if(d > fst){
                    scd = fst;
                    fst = d;
                }
                else if(d < fst && d > scd) scd = d;
            }
        }
        return scd;
    }
};