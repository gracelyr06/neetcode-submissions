class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // piles[i] / k -- 1 2 3 4 
        // h upper bound is max, and it takes x hrs to eat x bananas
        // h /= 2 
        // h *= 2 
        // 
        sort(piles.begin(), piles.end());
        int n = piles.size();
        int upper = piles[n - 1];
        int lower = 1;
        if (n == h) {
            return upper;
        }
        // 30 - mid 15 -  lower 
        // brute force search O(n*m)
        int mid = 0;
        int k = 0; 
        int ans = 0;
        while (lower <= upper) {
            mid = (upper + lower) / 2;
            k = 0;
            for (int pile: piles) {
                k += ceil((pile + mid - 1) / mid);
            } 
            if (k > h) {
                lower = mid + 1;
            } else if (k <= h) {
                ans = mid; // very important !!
                upper = mid - 1;
            } 
        }

        return ans;

    }
};
