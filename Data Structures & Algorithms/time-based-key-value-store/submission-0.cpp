class TimeMap {

private:
    unordered_map<string,map<int,string>> datastructure;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        datastructure[key].insert({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        auto it = datastructure[key].upper_bound(timestamp);
        return it == datastructure[key].begin() ? "" : prev(it)->second;
        
    }
};
