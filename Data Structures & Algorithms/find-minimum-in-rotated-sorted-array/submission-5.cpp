class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0;
        int right = nums.size() - 1;
        int minNum = nums[0];

        while (left <= right) {
            // If the current subsegment is already sorted, 
            // the leftmost element is the minimum of this range.
            if (nums[left] <= nums[right]) {
                minNum = min(minNum, nums[left]);
                break;
            }

            int mid = (left + right) / 2;
            minNum = min(minNum, nums[mid]);

            // If mid element is greater than or equal to left, 
            // the left half is sorted; the pivot must be in the right half.
            if (nums[mid] >= nums[left]) {
                minNum = min(minNum, nums[left]);
                left = mid + 1;
            } 
            // Otherwise, the right half is sorted; 
            // the pivot (minimum) is in the left half.
            else {
                right = mid - 1;
            }
        }
        return minNum;
    }
};
