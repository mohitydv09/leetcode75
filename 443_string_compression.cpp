#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        
        int count = 1;
        char curr_char = chars[0];
        int n = chars.size();
        int index = 0;

        // Edge case of only one element.
        if (n==1){return 1;};

        // Empty increment for loop.
        for (int i = 1; i < n;){
            // For the last item we need to do this loop.
            if (i == n-1){
                if (chars[i] == curr_char){
                    count++;
                    chars[index++] = curr_char;
                    string count_str = to_string(count);
                    for (char item : count_str){
                        chars[index++] = item;
                    }
                }else{
                    chars[index++] = curr_char;
                    if (count>1){
                        string count_str = to_string(count);
                        for (char item : count_str){
                            chars[index++] = item;
                        }
                    }
                    chars[index++] = chars[i];
                }
                i++;
                // return index;
            }else{
                if (chars[i] == curr_char){
                    // If the item is same as last one and this is not the last , increment the count and move on to the next one.
                    count++;
                    i++;
                }else{
                    if (count == 1){
                        // If only one char is present insert that item and move the index forward.
                        chars[index++] = curr_char;
                        curr_char = chars[i];
                        i++;
                    }else{
                        // This is for when the count is greater than one.

                        // If this is the last item
                        chars[index++] = curr_char;
                        //  Make the count a string and add accordingly.
                        string count_str = to_string(count);
                        for (char item : count_str){
                            chars[index++] = item;
                        }

                        curr_char = chars[i];
                        // Reset Count.
                        count = 1;
                        i++;
                    }
                }
            }
        }
        // Print the chars
        for (char item : chars){
            cout << item;
        }
        return index;
    }
};

int main(){
    Solution solution_instance;
    vector<char> chars = {'a','a','b','b','c','c','c'};
    // vector<char> chars = {'a','b','c'};
    cout << solution_instance.compress(chars) << endl;
    return 0;
}