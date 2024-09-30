class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (const string& token : tokens){
            if(isdigit(token.back())){
                s.push(stoi(token));
            }else{
                int n2 = s.top(); s.pop();
                int n1 = s.top(); s.pop();
                int n = 0;
                switch(token[0]){
                    case '+': n = n1+n2;break;
                    case '-': n = n1-n2;break;
                    case '*': n = n1*n2;break;
                    case '/': n = n1/n2;break;
                }
                s.push(n);
            }
        }
        return s.top();
        
        // for(int i=0;i<tokens.size();i++){
        //     if(tokens[i].size() == 1 && (tokens[i][0] == '+' || tokens[i][0] == '-' || tokens[i][0] == '*' || tokens[i][0] == '/'))
        //         number.push(stoi(tokens[i]));
        //     else{
        //         int n2 = number.top(); number.pop();
        //         int n1 = number.top(); number.pop();
        //         int n = 0;
        //         if(tokens[i][0] == '+'){
        //             n = n1+n2;
        //         }else if(tokens[i][0] == '-'){
        //             n = n1-n2;
        //         }else if(tokens[i][0] == '*'){
        //             n = n1*n2;
        //         }else
        //             n = n1/n2;
        //         number.push(n);
        //     }
        // }
        // return number.top();
    }
};