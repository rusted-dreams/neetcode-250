class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int num = -1;
        for(int i : nums) {
            if(i == num) count++;
            else count--;
            if(count <= 0) {
                num = i;
                count = 1;
            }
        }
        return num;
    }
};