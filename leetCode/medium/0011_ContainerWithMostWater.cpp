class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0;
        int r = n-1;
        int maxVal = 0;
        while(l < r){
            int a = min(height[l], height[r]) * (r-l);
            maxVal = max(maxVal, a);
            if(height[l] < height[r]){
                l+=1;
            }else{
                r-=1;
            }
        }
        return maxVal;
    }
};
