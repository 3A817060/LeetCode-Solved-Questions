class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> t_pool;   // temperature & index
        vector<int> ans(temperatures.size(), 0);
        t_pool.push({temperatures[0], 0});
        
        for(int i=1;i<temperatures.size();i++){
            while(!t_pool.empty() && temperatures[i] > t_pool.top().first){
                // Get the index from the top of the stack
                int prevIndex = t_pool.top().second;
                // calculate the difference in days
                ans[prevIndex] = i - prevIndex;
                // Pop the top element since we found the answer for it
                t_pool.pop();
            }
            t_pool.push({temperatures[i], i});
        }
        return ans;
    }
};