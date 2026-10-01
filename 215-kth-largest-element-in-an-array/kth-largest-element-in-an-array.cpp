class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        int target = nums.size() - k;

        int low = 0;
        int high = nums.size() - 1;

        while(low <= high) {

            int pivot = nums[high];
            int i = low;

            for(int j = low; j < high; j++) {

                if(nums[j] < pivot) {
                    int temp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = temp;

                    i++;
                }
            }

            int temp = nums[i];
            nums[i] = nums[high];
            nums[high] = temp;

            if(i == target) {
                return nums[i];
            }
            else if(i < target) {
                low = i + 1;
            }
            else {
                high = i - 1;
            }
        }

        return -1;
    }
};