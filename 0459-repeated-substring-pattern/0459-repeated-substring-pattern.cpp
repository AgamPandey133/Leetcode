class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        if(n == 1) return 0;

        vector<int> lps(n);
        int pre = 0;
        int suff = 1;

        lps[0] = 0;

        while(suff < n){
            if(s[pre] == s[suff]) {
                lps[suff] = pre+1;
                pre++;
                suff++;
            }else{
                if(pre == 0) {
                    lps[suff] = 0;
                    suff++;
                }else pre = lps[pre-1];
            }
        }

        int len = lps[n - 1];

        return (len > 0 && n % (n - len) == 0);
    }
};