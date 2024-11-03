class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_set<int> intSet;
        const int n = cards.size();
        int res = -1;
        bool flag = false;
        for(int l=0, r=0;r<n;++r){
            while(intSet.find(cards[r]) != intSet.end()){
                if(flag != true){
                    res = max(res, r-l+1);
                    flag = true;                   
                }else{
                    res = min(res, r-l+1);
                }
                intSet.erase(cards[l++]);
            }
            intSet.insert(cards[r]);
        }
        return res;
    }
};