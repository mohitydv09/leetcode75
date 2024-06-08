#include<iostream>
#include<stack>
using namespace std;

class StockSpanner {
public:
stack<pair<int, int>> monoStack; // Price and no of days on top.
    StockSpanner(){};

    int next(int price){
        if(monoStack.empty()){
            monoStack.push({price, 1});
            return 1;
        }else{
            int ans = 1;
            auto topItem = monoStack.top();
            while(topItem.first <= price){
                ans += topItem.second;
                monoStack.pop();
                if(!monoStack.empty()){
                    topItem = monoStack.top();
                }else{
                    break;
                }
            }
            monoStack.push({price, ans});
            return ans;
        }
    };
};

int main(){
    StockSpanner* obj = new StockSpanner();
    cout << obj->next(100) << endl;
    cout << obj->next(90) << endl;
    cout << obj->next(110) << endl;
    cout << obj->next(120) << endl;
}