// check notes
class TimeMap {
public:
    map<string, vector<pair<string, int>>>mp;

    TimeMap() {
        //map: key -> [{value1, timestamp1}, {value2, timestamp2}]    
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        string res="";

        if(mp.find(key) == mp.end()){
            return res;
        }

        vector<pair<string, int>> &vec = mp[key];
        //we can use binary search to find the corresponding value based on given
        //timestamp because time stamp is definitely going to increase with time
        //there for sorted and hence binary search we could use linear search too
        int start=0, end = vec.size()-1;

        while(start <= end){
            int mid = start + (end - start)/2;

            //if not found take the nearest smallest
            if(vec[mid].second <= timestamp){
                res = vec[mid].first;
                start = mid+1;
            }else{
                end = mid-1;
            }
        }

        return res;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */