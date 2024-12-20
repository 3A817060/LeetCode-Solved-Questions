class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> count;
        int res = 0;
        int maxf=0;
        for(int l=0, r=0;r<s.size();r++){
            count[s[r]]++;
            maxf = max(maxf, count[s[r]]);
            while((r-l+1)-maxf > k){
                count[s[l++]]--;
            }
            res = max(res, r-l+1);
        }
        return res;
    }
};