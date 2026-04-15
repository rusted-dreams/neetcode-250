class Solution {
    // Use array indices as a hash for values [1..n].
    // Key idea: answer lies in [1..n+1].

    // Steps:
    // 1. Convert all negative values to 0 (ignore irrelevant values).
    // 2. For each value x in [1..n], mark index (x-1) as visited by making it negative.
    //    - If value at index is 0, mark it as -(n+1) to distinguish from unvisited.
    // 3. First index i with non-negative value => missing number (i+1).
    // 4. If all indices are marked, answer is n+1.

public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] < 0 ) nums[i] = 0;
        }
        for(int i=0; i<nums.size(); i++) {
            int idx = abs(nums[i]) - 1;
            if(idx >= 0 && idx < nums.size() && nums[idx] >= 0){
                if(nums[idx] == 0) nums[idx] = -(nums.size()+1);
                else nums[idx] *= -1;
            }
        }
        for(int i=1; i<=nums.size(); i++) {
            if(nums[i-1] >= 0) return i;
        }
        return nums.size()+1;
    }
};