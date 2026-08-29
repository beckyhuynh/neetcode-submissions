class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size() - 1;
        int water = 0;

        while (left <= right) {
            water = max(water, (right-left)*min(heights[right],heights[left]));

            if (heights[right] >= heights[left]) {
                left ++;
            }
            else right --;
        }
        return water;
    }
};
