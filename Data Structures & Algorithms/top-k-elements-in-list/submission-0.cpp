class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        priority_queue<pair<int, int>> pq;
        unordered_map<int, int> mpp;
        for(int i : nums) {
            mpp[i]++;
        }
        for(auto &[k, v] : mpp) {
            pq.push({v, k});
        }
        for(int i = 0; i < k; i++) {
            pair<int, int> num = pq.top();
            pq.pop();
            ans.push_back(num.second);
        }
        return ans;
    }
};
