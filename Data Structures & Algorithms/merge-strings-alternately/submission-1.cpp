class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int a =0, b=0;
        string res = "";
        bool first = true;
        while(a < word1.size() && b < word2.size()) {
            if(first) {
                res += word1[a];
                a++;
            }
            else {
                res += word2[b];
                b++;
            }
            first = !first;
        }
        while(a < word1.size()) {
            res += word1[a];
            a++;
        }
        while(b < word2.size()) {
            res += word2[b];
            b++;
        }
        return res;

    }
};