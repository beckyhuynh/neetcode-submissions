class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        else{
            unordered_map<char,int> scount;
            unordered_map<char,int> tcount;
            for (int i = 0; i < s.length(); i++){
                scount[s[i]] ++;
                tcount[t[i]] ++;
            }

            for(auto pair : scount){
                if (tcount[pair.first] != pair.second) {
                    return false;
                }
            }
            return true;
        }
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> anagrams;
        for (string s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            anagrams[key].push_back(s);
        }

        vector<vector<string>> anagramsList;
        for (auto&pair : anagrams) {
            anagramsList.push_back(pair.second);
        }
        return anagramsList;
    }
};
