class Solution {
public:
    int maxScore(vector<int>& cards, int k) {
        int n = cards.size();
        int l = 0;
        int r = n - k;
        int total_pts = 0;
        int sum = 0;
        int ans = 0;

        for(int i = 0; i < n; i++) {
            total_pts += cards[i];
        }

        if (k == n) return total_pts;

        for(int i = 0; i < r; i++) {
            sum += cards[i];
        }

        ans = total_pts - sum;

        while(r < n) {
            sum -= cards[l++];
            sum += cards[r++];
            ans = max(ans, total_pts - sum);
        }

        return ans;
    }
};