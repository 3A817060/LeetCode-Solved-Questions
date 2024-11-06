class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left=0;
        int n=nums.size();
        int cnt=0,ans=0;
        for(int r=0;r<n;r++){
            if(nums[r]==0) 
                cnt++;
            if(cnt>k){
                while(nums[left]!=0 && left<r)
                    left++;
                left++;
                cnt--;
            }
            ans=max(ans,r-left+1);
        }
        return ans;
    }
};