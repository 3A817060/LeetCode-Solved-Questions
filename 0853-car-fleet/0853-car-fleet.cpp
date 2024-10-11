class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack <double> fleet;
        vector<vector<int>> cars;
        
        for(int i=0;i<position.size();i++)
            cars.push_back({position[i], speed[i]});
        
        sort(cars.begin(), cars.end(), [](const vector<int>& a, const vector<int>& b){
            return a[0]>b[0];
        });
        
        for(const auto& car : cars){
            double time = (double)(target - car[0])/car[1];
            if (!fleet.empty() && time <= fleet.top()) 
                continue;
            fleet.push(time);
        }
        return fleet.size();
    }
};