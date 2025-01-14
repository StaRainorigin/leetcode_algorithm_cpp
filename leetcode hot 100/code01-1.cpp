vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> arr(target + 1, 0);
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= target && nums[i] > 0)
                arr[nums[i]] = 1;
        }
        int left = 0, right = target;
        vector<int> results = {0, 0};
        while (left < right) {
            if (arr[left] && arr[right]) {
                results[0] = left;
                results[1] = right;
                break;
            }
            left++;
            right--;
        }
    return results; 
    }

