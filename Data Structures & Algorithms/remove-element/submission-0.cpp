class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left = 0, right = 0;
        while(left < nums.size()) {
            if(nums[left] == val) {
                while(right < nums.size() && nums[right] == val) {
                    right++;
                }
                if(right < nums.size()) swap(nums[left], nums[right]);
                else return left;
                left++;
                right++;
            }
            else {
                left++;
                if(right < left) right++;
            }
        }
        return left;
    }
};