class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int judge = trust[0][1];
        for(int i = 0; i<trust.size(); i++) {
            if(trust[i][0] == judge) return -1;
            else {
                if(trust[i][1] != judge) return -1;
            }
        }
        return judge;
    }
};