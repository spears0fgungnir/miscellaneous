class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0,j=height.size()-1,ans=0;
        while(i<j){
            int x=height[i],y=height[j];
            int vol=min(x,y)*(j-i);
            if(x<=y)i++;
            if(y<x)j--;
            ans=max(vol,ans);
        }
        return ans;
    }
};