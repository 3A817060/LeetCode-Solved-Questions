class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(result, "", 0, 0, n);
        return result;
    }
    
    void backtrack(vector<string> &output, string current_str, int open, int close, int n){
        if(current_str.length() == n*2){
            output.push_back(current_str);
            return ;
        }
        if(open < n){
            backtrack(output, current_str + '(', open + 1, close, n);
        }
        if(close < open){
            backtrack(output, current_str + ')', open, close + 1, n);
        }
    }
        
//         vector<vector<string>> alls(1, { "" });
        
//         for(int j=1; j<=n; j++){
//             vector<string> temp;
//             for(int i=0;i<j;i++)
//                 for(string& left : alls[i])
//                     for(string& right : alls[j-1-i])
//                         temp.push_back("(" + left + ")" + right);
//             alls.push_back(temp);
//         }
//         return alls[n];
};