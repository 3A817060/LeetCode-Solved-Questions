class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size();
        int l = 0;
        int r = len-1;
        int maxl = height[l];
        int maxr = height[r];
        int res = 0;
        while(l < r){
            if(maxl <= maxr){
                l++;
                res += max(0, maxl-height[l]);
                maxl = max(maxl, height[l]);
            }else{
                r--;
                res += max(0, maxr-height[r]);
                maxr = max(maxr, height[r]);
            }
        }
        return res;
    }
};