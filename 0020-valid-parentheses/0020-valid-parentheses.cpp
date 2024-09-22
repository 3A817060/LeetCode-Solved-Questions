class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> bracket_map = {{')', '('}, {']', '['}, {'}', '{'}};
        stack<char> bracket_pool;
        
        for (char c : s ){
            if(bracket_map[c]){
                if(!bracket_pool.empty() && bracket_pool.top() == bracket_map[c])
                    bracket_pool.pop();
                else
                    return false;
            }
            else
                bracket_pool.push(c);
        }
        return bracket_pool.empty()? true:false;
    }
};