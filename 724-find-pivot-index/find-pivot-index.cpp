class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        
        for(int i = 1; i < nums.size(); i++) {
            nums[i] += nums[i - 1];
        }

        int leftsum;
        for(int i = 0; i < nums.size(); i++) {
            if(i == 0) leftsum = 0;
            else leftsum = nums[i - 1];

            int rightsum = nums[n - 1] - nums[i];
            
            if(leftsum == rightsum) return i;
        }
        return -1; 
    }
};