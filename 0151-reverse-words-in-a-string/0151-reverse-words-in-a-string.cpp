class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();

        string ans = "";
        string str = "";
        for(int i = 0; i < n; i++){
            if(s[i] == ' '){
                if(str.empty() || str.back() == ' ') continue;
                ans = str + ' ' + ans;
                str = "";
            }else{
                str += s[i];
            } 
        }

        if(!str.empty()) ans = str + ' ' + ans;
        ans.pop_back();
        return ans;
        
    }
};