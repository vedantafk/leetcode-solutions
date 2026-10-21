class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        int ans = 0;

        for(int i = 1; i < n; i++) {
            nums[i] += nums[i-1];
        }

        for(int i =0; i < n; i++) {
            int rem = nums[i] % k;
            if(rem < 0) rem += k;

            if(rem == 0) ans++;

            if(mp.find(rem) != mp.end()) ans += mp[rem];

            mp[rem]++;
        }
        return ans;
    }
};