class Solution {
public:
    int maxArea(vector<int>& heights) {
        int front = 0;
        int back = heights.size()-1;
        int max = 0;
        while (front < back){
            // cout << front << back << endl;
            int area = min(heights.at(front),heights.at(back))*(back-front);
            if (area > max) max = area;
            if (heights.at(front) <= heights.at(back)) {
                front ++;
            }
            else if (heights.at(front) > heights.at(back)){
                back --; 
            }
        }
        // cout << max << endl;
        return max;
    }
};
