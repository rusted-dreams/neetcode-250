class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> hash;
        for(int i=0; i<order.size(); i++) {
            hash[order[i]] = i;
        }

        for(int i = 1; i < words.size(); i++) {
            string w2 = words[i];
            string w1 = words[i-1];

            int j = 0;
            for(; j < w1.size(); j++){
                if(j == w2.size()) return false;
                if(w1[j] != w2[j]) {
                    if(hash[w1[j]] > hash[w2[j]]) return false;
                    break;
                }
            }

        }
        return true;
        

    }
};