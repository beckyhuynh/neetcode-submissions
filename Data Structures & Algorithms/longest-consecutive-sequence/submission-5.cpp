class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return 1;
        int maxLength = 0;
        vector <set<int>> chains;
        set <int> currentChain;

        sort(nums.begin(),nums.end());
        
        for (int i = 0; i < nums.size()-1; i++) {
             // only insert into chain if its one more and not same number as last one 
            if (!currentChain.contains(nums.at(i))) currentChain.insert(nums.at(i));

            if ((nums.at(i+1) != nums.at(i)) && (nums.at(i+1)!= (nums.at(i)+1))){
                // dont continue the chain
                if (currentChain.size() != 0){
                    chains.push_back(currentChain);
                    currentChain.clear();
                }
            }

            else if (nums.at(i+1) == nums.at(i) + 1){
                currentChain.insert(nums.at(i+1));
            }
        }
        chains.push_back(currentChain);
        for (set<int> elem : chains){
            if (elem.size() > maxLength) maxLength = elem.size();
        }
        return maxLength;
    }
};
