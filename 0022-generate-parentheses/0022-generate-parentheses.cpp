class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> alls(1, { "" });
        
        for(int j=1; j<=n; j++){
            vector<string> temp;
            for(int i=0;i<j;i++)
                for(string& left : alls[i])
                    for(string& right : alls[j-1-i])
                        temp.push_back("(" + left + ")" + right);
            alls.push_back(temp);
        }
        return alls[n];
    }
};