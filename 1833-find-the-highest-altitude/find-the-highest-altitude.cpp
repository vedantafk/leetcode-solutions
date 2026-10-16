class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();

        for(int i = 1; i < n; i++) {
            gain[i] += gain[i - 1];
        }
        int altitude = 0;

        for(int i = 0; i < n; i++) {
            if(gain[i] >= 0) altitude  = max(gain[i], altitude);
        }
        return altitude;
    }
};