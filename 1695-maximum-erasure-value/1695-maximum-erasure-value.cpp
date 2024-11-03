class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        const int n = nums.size();
        unordered_set<int> intSet;
        int ans = 0;
        for(int l=0, r=0, s=0;r<n;++r){
            while(intSet.count(nums[r]) && l<r){
                s -= nums[l];
                intSet.erase(nums[l++]);
            }
            intSet.insert(nums[r]);
            ans = max(ans, s+=nums[r]);
        }
        return ans;
        
        
        // unordered_set<int> intSet;
        // int l = 0;
        // int res = 0;
        // for(int r=0;r<nums.size();r++){
        //     while(intSet.find(nums[r]) != intSet.end()){
        //         intSet.erase(nums[l]);
        //         l++;
        //     }
        //     intSet.insert(nums[r]);
        // }
        // for(auto it = intSet.begin();it != intSet.end();it++)
        //     res += *it;
        // return res;
    }
};