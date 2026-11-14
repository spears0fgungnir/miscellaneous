class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>>nnums(nums.size());
        for(int i=0;i<nums.size();i++)nnums[i]=make_pair(nums[i],i);
        sort(nnums.begin(),nnums.end());
        int i=0,j=nnums.size()-1;
        while(nnums[i].first+nnums[j].first!=target){
            int sum=nnums[i].first+nnums[j].first;
            if(sum>target)j--;
            else i++;
        }
        vector<int>ret={nnums[i].second,nnums[j].second};
        return ret;
    }
};