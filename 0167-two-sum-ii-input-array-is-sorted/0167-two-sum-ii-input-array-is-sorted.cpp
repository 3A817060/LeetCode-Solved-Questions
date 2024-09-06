class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> um;
        for (int i=0; i < numbers.size(); i++)
            um[numbers[i]]=i;
        for (int i=0; i< numbers.size(); i++){
            int complement = target - numbers[i];
            if (um.count(complement) && um[complement] != i)
                return {i+1, um[complement]+1};
        }
        // In case there is no solution, we'll just return null
        return {};
    }
};