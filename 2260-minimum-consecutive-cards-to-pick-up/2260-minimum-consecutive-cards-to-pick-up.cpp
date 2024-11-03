class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_set<int> intSet;
        const int n = cards.size();
        int res = INT_MAX ;
        bool flag = false;
        for(int l=0, r=0;r<n;++r){
            while(intSet.find(cards[r]) != intSet.end()){
                res = min(res, r-l+1);
                flag = true;
                intSet.erase(cards[l++]);
            }
            intSet.insert(cards[r]);
        }
        return flag ? res : -1;
    }
};