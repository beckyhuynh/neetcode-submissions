class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result;
        int res = 1;
        int zerocount = 0;
        int zeroInd = 0;
        // count zeros
        for (int i = 0; i < nums.size(); i++){
            if (nums.at(i) == 0){
                zerocount ++;
            }
        }

        if (zerocount == 0 | zerocount == 1){
            for (int i = 0; i < nums.size(); i++) {
                if (nums.at(i) != 0) {
                    res *= nums.at(i);
                }
                else {
                    zeroInd = i;
                }
            }
        }

        for (int i = 0; i < nums.size(); i++) {
            if (zerocount != 0) {
                if (zerocount == 1) {
                    if (i != zeroInd) result.push_back(0);
                    else result.push_back(res); 
                }

                if (zerocount > 1) {
                    result.push_back(0);
                }
            }
            else{
                result.push_back(res/(nums.at(i)));
            }
        }
        return result;
    }
};
