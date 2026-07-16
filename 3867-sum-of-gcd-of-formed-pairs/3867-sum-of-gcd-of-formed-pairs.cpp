class Solution {
public:
    using ll = long long;
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<ll> pre(n);
        ll maxi = nums[0];
        for(int i = 0; i < n; i++){
            maxi = max(maxi,nums[i]*1LL);
            pre[i] = gcd(1LL*nums[i], maxi);
        }

        sort(pre.begin(), pre.end());

        int i = 0, j = n-1;
        ll sum = 0;
        while(i < j){
            sum += gcd(pre[i], pre[j]);
            i++;
            j--;
        }

        return sum;
    }
};