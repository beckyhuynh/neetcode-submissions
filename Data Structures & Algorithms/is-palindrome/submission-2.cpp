class Solution {
public:
    bool isPalindrome(string s) {
        // construct string with only alphanumerical 
        vector <char> alphaNumString;
        for (int i = 0; i < s.length(); i++) {
            if ((s[i] >= 'a' && s[i] <= 'z') | (s[i] >= 'A' && s[i] <= 'Z') | (s[i] >= '0' && s[i] <= '9')) {
                char toPush = s[i];
                if (toPush >= 'A' && toPush <= 'Z') {
                    toPush = tolower(toPush);
                }
                alphaNumString.push_back(toPush);
                cout << toPush << endl;
            }
        }
        

        if (alphaNumString.size() == 0 | alphaNumString.size() == 1) return true;

        else {
            int length = alphaNumString.size() / 2;
            for (int i = 0; i < length; i++) {
                if (alphaNumString.at(i) != alphaNumString.at(alphaNumString.size()-1-i))return false;
            }
            return true;
            
        }
    }
};
