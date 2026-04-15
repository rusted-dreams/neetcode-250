class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = min(word1.size(), word2.size());
        string res = "";
        for(int i=0; i<n; i++) {
            res += word1[i];
            res += word2[i];
        }
        res = res + word1.substr(n) + word2.substr(n);
        return res;

    }
};