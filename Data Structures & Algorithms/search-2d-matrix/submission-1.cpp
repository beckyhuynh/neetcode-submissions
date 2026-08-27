class Solution {
public:

    static int search(vector<int>& nums, int target) {
        int medium = 0;
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right){
            medium = (left+right)/2;
            // cout << medium << endl;
            if (nums[medium] == target){
                return medium;
            }
            else if (nums[medium] < target){
                left = medium + 1;
            }
            else{
                right = medium - 1;
            }
        }

        cout << "got out" << endl;
        return -1;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // vector<int> listMatrix;
        // for (int i = 0; i < matrix.size(); i++){
        //     for (int j = 0; j < matrix[0].size(); j++){
        //         listMatrix.push_back(matrix[i][j]);
        //     }
        // }

        // if (search(listMatrix, target) != -1) {
        //     return true;
        // }
        // return false;
         for (int r = 0; r < matrix.size(); r++) {
            for (int c = 0; c < matrix[r].size(); c++) {
                if (matrix[r][c] == target) {
                    return true;
                }
            }
        }
        return false;
    }
};
