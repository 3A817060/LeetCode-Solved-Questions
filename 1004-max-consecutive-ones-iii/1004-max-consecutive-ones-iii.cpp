class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left=0;
        int n=nums.size();
        int cnt=0,ans=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0) 
                cnt++;
            if(cnt>k){
                while(nums[left]!=0 && left<i)
                    left++;
                left++;
                cnt--;
            }
            ans=max(ans,i-left+1);
        }
        return ans;
    }
};