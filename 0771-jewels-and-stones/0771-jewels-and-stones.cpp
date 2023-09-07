class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char, int> map;
        for(int i=0 ;i<stones.size() ;i++){
            map[stones[i]]++;
        }
        int cnt=0;
        for(auto i:map){
            for(int j=0; j<jewels.size(); j++){
                if(i.first == jewels[j])
                    cnt += i.second;      
            }
        }
        return cnt;
    }      
};