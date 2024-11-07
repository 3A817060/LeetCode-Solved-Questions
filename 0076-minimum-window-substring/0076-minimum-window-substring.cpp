class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() < t.size())
            return "";
        unordered_map<char, int> mp_s, mp_t;
        for(auto c : t) mp_t[c]++;
        const int n1=s.size(), need=t.size() ;
        
        int have=0;
        int minLen = INT_MAX;
        int minStart = 0;
        
        for(int l=0, r=0;r<n1;r++){
            if(mp_t[s[r]] > 0){
                mp_s[s[r]]++;
                // check if current count of s[r] in mp_s meets the count in mp_t
                if(mp_s[s[r]] <= mp_t[s[r]]) have++;
            }
            while(have == need){
                if(r - l + 1 < minLen){
                    minStart = l;
                    minLen = r - l + 1 ;   
                }
                
                if(mp_s[s[l]] > 0){
                    if(mp_s[s[l]] == mp_t[s[l]])
                        have--;
                    mp_s[s[l]]--;
                }
                l++;
            }
        }
        
        return minLen==INT_MAX ? "" : s.substr(minStart, minLen);
    }
};