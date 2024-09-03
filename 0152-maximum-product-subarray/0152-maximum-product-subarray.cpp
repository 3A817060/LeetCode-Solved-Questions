class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = nums[0];
        for(int i=1, h=ans, l=ans;i<nums.size(); ++i){
            if (nums[i]<0) swap(l, h);
            l = min(nums[i], nums[i]*l);
            h = max(nums[i], nums[i]*h);
            ans = max(ans, h);
        }
        return ans;
    }
};