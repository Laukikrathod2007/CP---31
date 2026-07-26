class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();

        // Product of the three biggest numbers
        int biggest = nums[n - 1] * nums[n - 2] * nums[n - 3];

        // Product of the two smallest numbers and the biggest number
        int negative = nums[0] * nums[1] * nums[n - 1];

        if (biggest > negative)
            return biggest;
        else
            return negative;
    }
};