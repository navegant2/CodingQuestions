


int searchCircularHelper(vector<int> nums, int start, int end, int target) {

    if (nums.size() == 0) {
        return -1;
    }
    if (start > end) { return -1; }

    int mid = start + (end - start)/2;
    
    if (nums[mid] == target) {
        return mid;
    }
    if (nums[start] < nums[mid]) {
        if (target >= nums[start] && target < nums[mid]) {
            return searchCircularHelper(nums, start, mid-1, target);
        }
        return searchCircularHelper(nums,mid+1, end, target);
    }
    if (target > nums[mid] && target <= nums[end]) {
        return searchCircularHelper(nums, mid+1, end, target);
    }
    return searchCircularHelper(nums, start, mid-1, target);
}
int searchCircular(vector<int> nums, int target) {
    searchCircularHelper(nums, 0, nums.size() - 1, target);
}
