class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()<3)
            return *max_element(nums.begin(),nums.end());
        vector<int>dp(nums.size());
        for(int i=0;i<2;i++)
            dp[i]=nums[i];
        for(int i=2;i<dp.size();i++)
            dp[i]=nums[i]+((i>=3)?max(dp[i-2],dp[i-3]):dp[i-2]);
        return max(dp[dp.size()-1],dp[dp.size()-2]);
    }
};

