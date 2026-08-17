class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // perform binary search on array
        // median - center of the two arrays, after merged 
        // half is 4
        // 1 3 4 5 9 -- 4.5
        // 2 6 7
        // 1 6 
        // four pointers in control 
        // even - 2 mid
        // odd - 1 mid 
        // similar to rotating - but left > right section is not guaranteed 

        // ascending 
        // median must be /2

        // 3  right 
        // left 6  
        // 3 4 5  -- 4, 6
        // 2 6 7


        // A: x 
        // B: half - x
        vector<int>& A = (nums1.size() <= nums2.size()) ? nums1 : nums2;
        vector<int>& B = (nums1.size() > nums2.size()) ? nums1 : nums2;

        // until a valid partition left of A <= right of B and left of B <= right of A
        int m = A.size();
        int n = B.size();
        int half = (m + n + 1) / 2; // if it is odd 
        int left = 0;
        int right = m;

        while (left < right) { // edge check
            //(A[x] <= B[half - x + 1] && B[half - x] <= A[x + 1] )
            // x < m && half - x < n  both always hold 
            int x = left + (right - left) / 2;
            int y = half - x;
            int Aleft = (x == 0) ? INT_MIN : A[x - 1];
            int Aright = (x == m) ? INT_MAX : A[x];

            int Bleft = (y == 0) ? INT_MIN : B[y - 1];
            int Bright = (y == n) ? INT_MAX : B[y];
            
            if (Aleft <= Bright && Bleft <= Aright) {
                if ((m + n) % 2 == 0) {
                    return (double)(max(Aleft, Bleft) + min(Aright, Bright)) / 2.0;
                }
                return max(Aleft, Bleft);
            }
            if (Aleft > Bright) { // move x to the left
                right = x - 1;
            } else if (Bleft > Aright) {
                left = x + 1;
            }

        }
        

    }
};
