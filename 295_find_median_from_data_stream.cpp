#include<iostream>
#include<queue>

class MedianFinder {
    std::priority_queue<int, std::vector<int>> firstHalf;
    std::priority_queue<int, std::vector<int>, std::greater<int>> secondHalf; 

public:
    MedianFinder() {}
    
    void addNum(int num) {
        firstHalf.emplace(num);
        if(secondHalf.size() > 0){
            if(firstHalf.top() > secondHalf.top()){
                secondHalf.emplace(firstHalf.top());
                firstHalf.pop();
            }
        }
        if(firstHalf.size() > secondHalf.size() + 1){
            secondHalf.emplace(firstHalf.top());
            firstHalf.pop();
        }
        if(secondHalf.size() > firstHalf.size() + 1){
            firstHalf.emplace(secondHalf.top());
            secondHalf.pop();
        }
    }
    
    double findMedian() {
        if(secondHalf.empty()){
            return firstHalf.top();
        }
        if(firstHalf.size() == secondHalf.size()){
            return (firstHalf.top() + secondHalf.top()) / 2.0;
        }else if(firstHalf.size() > secondHalf.size()){
            return firstHalf.top();
        }else{
            return secondHalf.top();
        }
        return 0.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main(){
    MedianFinder* obj = new MedianFinder();
    obj->addNum(1);
    double med = obj->findMedian();
    std::cout << "Median: " << med << std::endl;
    obj->addNum(2);
    med = obj->findMedian();
    std::cout << "Median: " << med << std::endl;
    obj->addNum(3);
    med = obj->findMedian();
    std::cout << "Median: " << med << std::endl;
    obj->addNum(4);
    med = obj->findMedian();
    std::cout << "Median: " << med << std::endl;
}