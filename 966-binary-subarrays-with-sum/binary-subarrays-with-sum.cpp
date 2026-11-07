class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int count = 0;
        unordered_map<int,int> mp;
        mp[0] = 1;
        
        for(int i = 1; i < n; i++) {
            nums[i] += nums[i - 1];
        }

        for(int i = 0; i < n; i++) {
            int k = nums[i] - goal;

            if(mp.find(k) != mp.end()) {
                count += mp[k];
            }
            mp[nums[i]]++;
        }
        // 1,1,2,2,3
        return count;
    }
};