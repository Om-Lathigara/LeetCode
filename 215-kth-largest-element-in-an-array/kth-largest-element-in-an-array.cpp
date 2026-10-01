class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        int target = nums.size() - k;

        int low = 0;
        int high = nums.size() - 1;

        while(low <= high) {

            int pivot = nums[low + (high - low) / 2];

            int i = low;
            int j = high;

            while(i <= j) {

                while(nums[i] < pivot) {
                    i++;
                }

                while(nums[j] > pivot) {
                    j--;
                }

                if(i <= j) {
                    int temp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = temp;

                    i++;
                    j--;
                }
            }

            if(target <= j) {
                high = j;
            }
            else if(target >= i) {
                low = i;
            }
            else {
                return nums[target];
            }
        }

        return -1;
    }
};