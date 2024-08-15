#include<iostream>
#include<string>
#include<unordered_map>

class TimeMap {
// Make the HashMap
private:
    std::unordered_map<std::string, std::vector<std::pair<int, std::string>>> hashMap;

public:
    TimeMap() {

    }
    
    void set(std::string key, std::string value, int timestamp) {
        hashMap[key].push_back({timestamp, value});
    }
    
    std::string get(std::string key, int timestamp) {
        int left = 0;
        int right = hashMap[key].size() - 1;
        int mid;
        std::string answer = "";
        while(left <= right){
            mid = (left + right)/2;
            if(hashMap[key][mid].first <= timestamp){
                answer = hashMap[key][mid].second;
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
        return answer;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

int main() {
    TimeMap* obj = new TimeMap();
    obj->set("mohit", "yadav", 1);
    obj->set("mohit", "yadav2", 2);
    obj->set("mohit", "yadav4", 4);
    obj->set("mohit", "yadav10", 10);
    obj->set("mohit", "yadav14", 14);
    std::string output = obj->get("mohit", 12);
    std::cout << output << std::endl;
}