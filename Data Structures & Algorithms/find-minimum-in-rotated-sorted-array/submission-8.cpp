class Solution {
public:
    int findMin(vector<int> &nums) {
        // narrow down the window until we find the one smaller than anything on the right and 
        // the one left to that bigger than anything on the left 
        int left = 0; 
        int right = nums.size() - 1;
        if (nums[0] < nums[right]) return nums[0];
        while (left < right) {
            int mid = left + (right - left) / 2;
            // if (mid > 0 && nums[mid] < nums[mid - 1]) {
            //     return nums[mid];
            // } 
            // if (nums[mid] < nums[0]) {
            //     right = mid - 1;
            // } else if (nums[mid] >= nums[0]) {
            //     left = mid + 1;
            // } 
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return nums[right];
    }
};
