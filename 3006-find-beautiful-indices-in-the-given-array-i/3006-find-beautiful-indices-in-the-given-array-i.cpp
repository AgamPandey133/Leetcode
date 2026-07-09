class Solution {
public:
    void fillLPSArray(string &s, vector<int>&lps){
        int n = s.size();

        int i = 0, j = 1;
        while(j < n){
            if(s[i] == s[j]){
                lps[j] = i+1;
                j++; i++;
            }else{
                if(i == 0) lps[j++] = 0;
                else i = lps[i-1];
            }
        }
    }

    vector<int> findAllOccurance(string &s, string &a){
        int n = s.size();
        int m = a.size();

        vector<int> lps (m);
        fillLPSArray(a, lps);

        vector<int> v;
        int i = 0, j = 0;
        while(i < n){
            if(s[i] == a[j]){
                i++; j++;
                if(j == m) {
                    v.push_back(i-m);
                    j = lps[j-1];
                }
            }else{
                if(j == 0) i++;
                else j = lps[j-1];
            }
        }

        return v;
    }

    vector<int> beautifulIndices(string s, string a, string b, int k) {
        int n = s.size();
        int m1 = a.size();
        int m2 = b.size();

        vector<int> va = findAllOccurance(s,a);
        vector<int> vb = findAllOccurance(s,b);

        vector<int> ans;
        for(int i = 0; i < va.size(); i++){
            vector<int> target = {va[i] - k, va[i] + k};
            int s = 0, e = vb.size()-1;
            while(s <= e){
                int mid = s + (e-s)/2;

                if(vb[mid] >= target[0] && vb[mid] <= target[1]){
                    ans.push_back(va[i]);
                    break;
                }else if(vb[mid] < target[0]) s = mid+1;
                else e = mid-1;
            }
        }

        return ans;
    }
};