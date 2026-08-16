int solve(vector<int>& nums, int low, int high)
{
    if(low==high) return nums[low];
    else{
    int mid = (low+high)/2;

    int left = solve(nums, low, mid);
    int right = solve(nums, mid+1, high);

    int sum = 0;
    int bestleft = nums[mid];

    for(int i = mid; i >= low; i--){
    sum += nums[i];
    if(sum > bestleft) bestleft = sum;
        
    }

    int sum1 = 0;
    int bestright = nums[mid+1];

    for(int i=mid+1;i<=high;i++){
        sum1 += nums[i];
        if(sum1 > bestright) bestright = sum1;
    }

    int cross = bestleft + bestright;

    return max(left, max(right, cross));
    }
}

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return solve(nums, 0, nums.size()-1);
    }
};