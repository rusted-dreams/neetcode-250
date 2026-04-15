class Solution {
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