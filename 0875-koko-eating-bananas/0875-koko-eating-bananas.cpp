class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        const int n = piles.size();
        sort(piles.begin(), piles.end());
        int l = 1;
        int r = piles[n-1];
        while(l <= r){
            int mid = (l + r)/2;
            double cnt = 0;
            for(int i=0;i<n;i++){
                cnt += ceil((double)piles[i]/mid);
            }
            // if(cnt==h)
            //     return mid;
            if(cnt<=h)
                r=mid-1;
            else
                l=mid+1;
        }
        return l;
    }
};