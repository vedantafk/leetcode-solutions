class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size();
        for(int i = 1; i < n;i++) {
            nums[i] += nums[i-1];
        }

        int leftsum = 0;
        for(int i = 0; i < n; i++) {
            int rightsum = nums[n-1] - nums[i];

            if(leftsum == rightsum) return i;
            leftsum = nums[i];
        }
        return -1;
    }
};