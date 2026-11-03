class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        mp[0] = -1;
        int maxlen = 0;

        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) {
                nums[i] = -1;
            }
            if(i > 0) {
                nums[i] += nums[i-1];
            }
        }

        for(int i = 0; i < n; i++) {
            if(mp.find(nums[i]) != mp.end()) {
                maxlen = max(maxlen, i - mp[nums[i]]);
            }
            else mp[nums[i]] = i;
        }  
        return maxlen;           
    }
};