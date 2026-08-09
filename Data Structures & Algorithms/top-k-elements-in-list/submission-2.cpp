class Solution {
public:
    static bool cmp(pair<int, int>& a, pair<int, int>& b) 
        { 
            return a.second > b.second; 
        } 

    vector<int> topKFrequent(vector<int>& nums, int k) {
        // counting frequency of occurence and putting it in map
        map <int,int> frequencyCount;
        for (int i = 0; i < nums.size(); i++) {
            frequencyCount[nums.at(i)] ++;
        }

        // sorting the map by count of occurence
        vector<pair<int,int>> sortCount;
        for (auto& pair : frequencyCount){
            sortCount.push_back(pair);
        }

        sort(sortCount.begin(),sortCount.end(),cmp);

        vector <int> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(sortCount.at(i).first);
        }
        return ans;
        
    }
};
