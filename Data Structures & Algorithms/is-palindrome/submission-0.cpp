class Solution {
public:
    bool isPalindrome(string s) {
        string cleanStr = "";
        for(char c : s) {
            c = tolower(c);
            if((c >= 'a' && c <= 'z') || (c <= '9' && c >= '0')) 
                cleanStr += c;
        }

        int l = 0, r = cleanStr.size() -1;
        while(l < r) {
            if(cleanStr[l] != cleanStr[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};
