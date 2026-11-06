class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if(n < 2) return false;

        unordered_map<int, int> mp;
        for(int i = 1; i < n; i++) {
            nums[i] += nums[i-1];
        }

        for(int i = 0; i < n; i++) {
            int r = nums[i] % k;

            if(r == 0 && i >= 1) return true;
            
            if(mp.find(r) != mp.end()) {
                if(i - mp[r] >= 2)  return true;
           }
           else {
            mp[r] = i;
           }
        }
        return false;
    }
};