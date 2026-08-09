class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        else{
            unordered_map<char,int> scount;
            for (int i = 0; i < s.length(); i++){
                scount[s[i]] ++;
            }

            unordered_map<char,int> tcount;
            for (int i = 0; i < t.length(); i++){
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
};
