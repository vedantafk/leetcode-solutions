class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for (int i = 0; i < n - 2; i++) {
            if(i > 0) if(nums[i] == nums[i-1]) continue;
            int L = i + 1;
            int R = n - 1;

            while (L < R) {
                if (nums[L] + nums[R] == -nums[i]) {
                    ans.push_back({nums[i], nums[L], nums[R]});
                    L++;
                    R--;
                    while (L < R && nums[L] == nums[L - 1]) L++;
                    while (L < R && nums[R] == nums[R + 1]) R--;
                }

                else if (nums[L] + nums[R] < -nums[i])
                    L++;
                else
                    R--;
            }
        }
        return ans;
    }
};