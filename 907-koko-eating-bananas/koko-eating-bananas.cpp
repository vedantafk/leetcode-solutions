class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int st = 1;
        int en = INT_MIN;
        for(int i = 0; i < n; i++) {
            en = max(piles[i], en);
        }

        while(st <= en) {
            int mid = (st + en)/2;

            long int hours = 0;
            for(int pile : piles){
            int div = pile / mid;
            hours += div;
            if(pile % mid != 0) hours++;
            }

            if(hours <= h) en = mid - 1;
            else st = mid + 1;
        }
        return st;
    }
};