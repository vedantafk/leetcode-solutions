class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftsum(n);
        vector<int> rightsum(n);
        vector<int> ans(n);
        
        int lftsum = 0;

        for(int i = 0; i < n; i++) {
            leftsum[i] = lftsum;
            lftsum += nums[i];
        }

        int rgtsum = 0;

        for(int i = n - 1; i >= 0; i--) {
            rightsum[i] = rgtsum;
            rgtsum += nums[i];
        }

        for(int i = 0; i < n; i++) {
            ans[i] = abs(leftsum[i] - rightsum[i]);
        }
        return ans;
    }
};