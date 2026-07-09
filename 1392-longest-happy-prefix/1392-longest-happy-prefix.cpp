class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size();
        if(n == 1) return "";

        vector<int> lps(n,0);
        int i = 0, j = 1;

        while(j < n){
            if(s[i] == s[j]){
                lps[j] = i+1;
                i++; j++;
            }else{
                if(i == 0){
                    lps[j] = 0;
                    j++;
                }else i = lps[i-1];
            }
        }

        return s.substr(0, lps[n-1]);
    }
};