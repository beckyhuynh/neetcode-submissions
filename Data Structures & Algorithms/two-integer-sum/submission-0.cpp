class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++){
            for (int j = 0; j < nums.size(); j++){
                if (j != i){
                    if (nums.at(i) + nums.at(j) == target) {
                        vector<int> ans = {i,j};
                        return ans;
                    }
                }
            }
        }
    }
};
