class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>count(128,-1);  
        int left = 0;
        int right = 0;
        int length = 0;

        while (right < s.length()) {
            if (count[s[right]] >= left) {
                left = count[s[right]] + 1;
            }
            count[s[right]] = right;
            
            length = max(length, right-left+1);
            right ++;
        }
        return length;
    }
};
