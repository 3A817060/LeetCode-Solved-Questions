class TimeMap {
public:
    /** Initialize your data structure here. */
    unordered_map <string, vector < pair <int, string > > >m;
    TimeMap() {
        m.clear();
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        string ret = "";
        vector <pair <int, string> >& v = m[key];
        int low = 0;
        int high = v.size() - 1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(v[mid].first <= timestamp){
                ret = v[mid].second;
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return ret;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */