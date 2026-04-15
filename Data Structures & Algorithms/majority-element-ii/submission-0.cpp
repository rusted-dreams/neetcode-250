class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for(int i : nums) {
            mpp[i]++;
        }
        vector<int> res;
        for(auto& [k, v] : mpp) {
            if(v > nums.size()/3) res.push_back(k);
        }
        return res;
    }
};