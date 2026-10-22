class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int L = 0; int R = 0;
        int count = 0;
        long int product = 1;
        if(k <= 1) return 0;

        while(R < nums.size()) {

            product *= nums[R];

            while(product > k) {
                product /= nums[L];
                L++;
            }
            if(product < k) count += R - L + 1;
            R++;
        }
        return count;
    }
};