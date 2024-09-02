int maxSubArray(int* nums, int numsSize) {
    
    // Kadane's Algorithm
    int max_current_sum=0, max_global_sum=INT_MIN;
    
    for (int i=0;i<numsSize;i++){
        max_current_sum = max_current_sum + nums[i];
        
        if(max_current_sum > max_global_sum)
            max_global_sum = max_current_sum;
        
        if(max_current_sum < 0)
            max_current_sum=0;
    }
    return max_global_sum;
}