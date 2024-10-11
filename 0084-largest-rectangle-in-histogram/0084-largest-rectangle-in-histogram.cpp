class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> indices;
        int global_area = 0;
        heights.push_back(0);
        for(int i=0;i<heights.size();++i){
            while(!indices.empty() && heights[i] < heights[indices.top()]){
                int h = heights[indices.top()];
                    indices.pop();
                int width = indices.empty() ? i : i - indices.top()-1;
                global_area = max(global_area, h*width);
            }
            indices.push(i);
            // min_heights = min(heights[i], min_heights);
            // global_area = min_heights * (i+1) ;
            // if(heights[i] > ans.top())
            //     ans.push();
        }
        return global_area;
    }
};