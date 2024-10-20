class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        if(matrix.empty())
            return false;
        
        const int m = matrix.size();
        const int n = matrix[0].size();
        int l = 0;
        int r = m*n;
        
        while(l < r){
            const int mid = (l + r) / 2;
            const int i = mid / n;
            const int j = mid % n;
            if(matrix[i][j] == target)
                return true;
            if(matrix[i][j] < target)
                l = mid + 1;
            else r = mid;
        }
        return false;
        
        // int m_l = 0;
        // int m_r = matrix.size() - 1;
        // while(m_l <= m_r){
        //     int m_m = m_l + (int)(m_r-m_l)/2;
        //     if(matrix[m_m][0] <= target && matrix[m_m].back() >= target){
        //         int l = 0;
        //         int r = matrix[m_m].size() - 1;
        //         while(l <= r){
        //             int mid = l + (r-1)/2;
        //             if(matrix[m_m][mid]==target){
        //                 return true;
        //             }else if(matrix[m_m][mid]<target){
        //                 l = mid+1;
        //             }else{
        //                 r = mid-1;
        //             }
        //         }
        //     }else if(matrix[m_m][0] < target){
        //         m_l = m_m+1;
        //     }else{
        //         m_r = m_m-1;
        //     }
        // }
        // return false;
    }
};