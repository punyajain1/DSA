class Solution {
public:
// in this question we are doing a devide and conqure , we devide list into smaller parts and do the fuction of checking revrse pairs and after rever pair merge it , after merge of one part we move up and sorted merge part is being compared to other unsorted or un merged part
     long long mergeAndCount(vector<int>& nums, int left, int mid, int right) {
        vector<int> merged;
        int j = mid + 1;
        long long cnt = 0;
        //here reverse paris are getting checked
        for (int i = left; i <= mid; i++) {
            while (j <= right && nums[i] > 2LL * nums[j]) {
                j++;
            }
            cnt += j-(mid+1);
        }
        int i = left;
        j = mid + 1;
        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j]) {
                merged.push_back(nums[i]);
                i++;
            } else {
                merged.push_back(nums[j]);
                j++;
            }
        }
        while (i <= mid) {
            merged.push_back(nums[i]);
            i++;
        }
        while (j <= right) {
            merged.push_back(nums[j]);
            j++;
        }
 
        int mergedSize = merged.size();
 
        for (int index = 0; index < mergedSize; index++) {
            nums[left + index] = merged[index];
        }
 
        return cnt;
    }

    long long mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right) {
            return 0;
        }
 
        int mid = left + (right - left) / 2;
        long long cnt = 0;
 
        cnt += mergeSort(nums, left, mid);
 
        cnt += mergeSort(nums, mid + 1, right);

        cnt += mergeAndCount(nums, left, mid, right);
 
        return cnt;
    }
    int reversePairs(vector<int>& nums) {
        if (nums.size() <= 1) {
            return 0;
        }
        int n = nums.size();
        return mergeSort(nums, 0, n - 1);
    }
};