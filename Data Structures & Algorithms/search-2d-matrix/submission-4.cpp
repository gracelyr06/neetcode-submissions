class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left = 0; 
        int right = matrix.size() - 1;
        // 0 2 - mid = 1
        while (left < right) {
            int mid = (left + right) / 2;

            if (matrix[mid][0] < target) {
                left = mid + 1;
            } else if (matrix[mid][0] > target) {
                right = mid - 1;
            } else {
                return true;
            }
        }

        if (matrix[left][0] > target){
            left--;
            if (left == -1) return false; // not found
        }
        int colleft = 0; 
        int colright = matrix[0].size() - 1;

        while (colleft <= colright) {
            int mid = (colleft + colright) / 2;

            if (matrix[left][mid] < target) {
                colleft = mid + 1;
            } else if (matrix[left][mid] > target) {
                colright = mid - 1;
            } else {
                return true;
            }
        }

        return false;

    }
};
