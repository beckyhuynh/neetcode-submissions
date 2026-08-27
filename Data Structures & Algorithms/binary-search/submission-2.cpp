class Solution {
public:
    int search(vector<int>& nums, int target) {
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
};
