class Solution {
    // 1. store each no. in a set.
    // 2. iterate over the set and only look for sequence if a no. lower than
    //      the current no. is not found. i.e. it can be the start of a sequence.
    // 3. time complexity is around O(3n).
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        for(int i=0; i<n; i++){
            st.insert(nums[i]);
        }
        int ans = 0;
        int count = 1;
        for(int i : st) {
            int num = i;
            if(st.find(i-1) != st.end()) continue;
            while(true) {
                if(st.find(num+count) != st.end()) {
                    count++;
                }
                else {
                    ans = max(ans, count);
                    count = 1;
                    break;
                }
            }
        }
        return ans;
    }
};
