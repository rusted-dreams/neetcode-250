class Solution {
    // 1. sliding window comes to mind.
    // 2. find all sub arr with sum <= k
    // 3. find all sub arr with sum <= k-1.
    // 4. ans is sum1 - sum2.
    // - this won't work since nums has -ve values.

    
    // Intuition:
    // - Use prefix sum to convert subarray sum problem into a lookup problem.
    // - For each index, we have current prefixSum.
    // - We want: prefixSum[j] - prefixSum[i] = k
                // → prefixSum[i] = prefixSum[j] - k
    // - So, for current prefixSum, check how many times (prefixSum - k) has appeared before.
    // - Store frequency of prefix sums in a hashmap.

    // Why prefixSumCount[0] = 1?
    // - Handles subarrays starting from index 0.
    
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSumCount; // prefixSum -> frequency
        int prefixSum = 0;
        int ans = 0;
        prefixSumCount[0] = 1;

        for (int num : nums) {
            prefixSum += num;
            int required = prefixSum - k;
            if (prefixSumCount.count(required)) {
                ans += prefixSumCount[required];
            }
            prefixSumCount[prefixSum]++;
        }
        return ans;
    }
};