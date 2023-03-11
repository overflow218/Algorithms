#include<unordered_map>
#include<vector>
#include <algorithm>
using namespace std;

class TimeMap {
public:
    unordered_map<string, vector<int>> times;
    unordered_map<string, vector<string>> values;
    TimeMap() {    
    }
    
    void set(string key, string value, int timestamp) {
        if(this -> times.find(key) == this -> times.end())
        {
            this -> times[key] = {timestamp};
            this -> values[key] = {value};
        } else 
        {
            this -> times[key].push_back(timestamp);
            this -> values[key].push_back(value);
        }
    }
    
    string get(string key, int timestamp) {
        if(this -> times.find(key) == this -> times.end()) return "";
        if(this -> times[key].back() <= timestamp)
        {
            return this -> values[key].back();
        }

        int idx = lower_bound(this -> times[key].begin(), this -> times[key].end(), timestamp) - this -> times[key].begin();

        if(this -> times[key][idx] > timestamp) idx--;
        if(idx < 0) return "";
        return this -> values[key][idx];
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */