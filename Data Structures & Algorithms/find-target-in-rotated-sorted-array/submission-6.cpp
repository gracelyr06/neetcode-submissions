class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        // find the smallest - left
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        // left if smallest
        // 1
        if (target == nums[left]) {
            return left;
        } else if (target > nums[nums.size() - 1]) { // 0 to left - 1
            right = left - 1;
            left = 0;
        } else { // left to size - 1
            right = nums.size() - 1;
        }

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                return mid;
            }
        }

        return -1;
    }
};
