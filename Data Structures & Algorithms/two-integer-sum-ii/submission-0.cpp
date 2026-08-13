class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int indexFront = 0;
        int indexBack = numbers.size() - 1;
        
        while (true) {
            if (numbers.at(indexFront) + numbers.at(indexBack) == target){
                return {indexFront + 1, indexBack + 1};
            }
            else if (numbers.at(indexFront) + numbers.at(indexBack) > target) {
                indexBack --;
            
            }
            else if (numbers.at(indexFront) + numbers.at(indexBack) < target) {
                indexFront ++;
            }
        }
    }
};
