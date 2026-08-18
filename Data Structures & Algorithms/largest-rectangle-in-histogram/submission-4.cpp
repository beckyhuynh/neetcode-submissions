class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector <int> rightBoundaries(heights.size(),heights.size());
        vector <int> leftBoundaries(heights.size(),-1);
        stack <int> idxTrack;
        // go left to right to find the left boundary
        for (int i = 0; i < heights.size(); i++){
            while (!idxTrack.empty() && heights.at(i) <= heights.at(idxTrack.top())){
                idxTrack.pop();
            }

            if (!idxTrack.empty()){
                leftBoundaries[i] = idxTrack.top();
            }

            idxTrack.push(i);
        }

        while (!idxTrack.empty()) idxTrack.pop();

        for (int i = heights.size()-1; i >= 0; i--){
            while (!idxTrack.empty() && heights.at(i) <= heights.at(idxTrack.top())){
                idxTrack.pop();
            }

            if (!idxTrack.empty()){
                rightBoundaries[i] = idxTrack.top();
            }

            idxTrack.push(i);
        }

        int maxArea = 0;
        for (int i = 0; i < heights.size(); i++){
            leftBoundaries[i] +=1;
            rightBoundaries[i] -= 1;
            maxArea = max(maxArea, heights[i]*(rightBoundaries[i] - leftBoundaries[i] + 1));
        }
        return maxArea;
    }
};
