
class Solution {
    public boolean predictTheWinner(int[] nums) {
        
        int n = nums.length;
        int[][] dp = new int[n][n];

        // base case => end1 = end2
        for(int i=0;i<n;i++){
            dp[i][i] = nums[i];
        }
        
        // starting from n-2 since n-1, n-1 
        for(int end1 = n-2; end1>=0; end1--){
            // checking all intervals here
            for(int end2=end1+1;end2<n;end2++){
                dp[end1][end2] = Math.max(nums[end1]-dp[end1+1][end2], nums[end2]-dp[end1][end2-1]); 
            }
        }

        return dp[0][n-1]>=0;

    }

}