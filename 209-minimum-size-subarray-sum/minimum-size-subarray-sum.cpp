class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int L = 0;
        int R = 0;
        int minlen = INT_MAX;
        int sum = 0;

        while(R < nums.size()) {
            sum += nums[R];

            while(sum >= target) {
                minlen = min(minlen, R - L + 1);

                sum -= nums[L];
                L++;
            }       
            R++;
        }
        if(minlen == INT_MAX) return 0;
        return minlen;
    }
};