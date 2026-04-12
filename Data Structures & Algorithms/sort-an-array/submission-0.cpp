class Solution {
    void merge(vector<int> &arr, int start, int mid, int end){
        int left=start, right=mid+1;
        vector<int> temp;
        while(left <= mid && right <= end) {
            if(arr[left] <= arr[right]){
                temp.push_back(arr[left]);
                left++;
            }
            else {
                temp.push_back(arr[right]);
                right++;
            }
        }

        while(left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }
        while(right <= end) {
            temp.push_back(arr[right]);
            right++;
        }
        int j = 0;
        for(int i=start; i<= end; i++) {
            arr[i] = temp[j];
            j++;
        }
    }
    void mergeSort(int start, int end, vector<int>& nums) {
        if(start >= end) return;
        int mid = start + (end-start)/2;

        mergeSort(start, mid, nums);
        mergeSort(mid+1, end, nums);
        merge(nums, start, mid, end);
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(0, nums.size()-1, nums);
        return nums;
    }
};