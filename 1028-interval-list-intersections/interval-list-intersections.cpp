class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>>result;
        auto left=firstList.begin();
        auto right=secondList.begin();
        while(left!=firstList.end()&&right!=secondList.end()){
            int start=max((*left)[0],(*right)[0]);
            int end=min((*left)[1],(*right)[1]);
            if(start<=end)
                result.push_back({start,end});
            if((*left)[1]<(*right)[1])
                left++;
            else
                right++;
        }
        return result;
    }
};