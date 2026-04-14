class Solution {
    // 1. sliding window comes to mind.
    // 2. find all sub arr with sum <= k
    // 3. find all sub arr with sum <= k-1.
    // 4. ans is sum1 - sum2.
    // - this won't work since nums has -ve values.

    
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixCount; // prefixSum, freq.
        int ans = 0;
        prefixCount[0] = 1;
        int currSum = 0;
        for(int i =0; i<nums.size(); i++) {
            currSum += nums[i];
            if(prefixCount.find(currSum - k) != prefixCount.end()){
                ans += prefixCount[currSum - k];
            }
            prefixCount[currSum]++;
        }
        return ans;
    }
};