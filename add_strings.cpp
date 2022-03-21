// File Name: add_strings.cpp
// Author: Meghan Bhatia
// Description: Given two non-negative integers, num1 and num2 represented
// as string, return the sum of num1 and num2 as a string.

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        string rv = "";
        int carry = 0, ind1 = num1.size(), ind2 = num2.size();
        while(ind1>0 && ind2>0){
            int curr = int(num1[ind1-1]) + int(num2[ind2-1]) + carry - 96;
            carry = curr/10;
            char curr_str = char(curr%10 + 48);
            rv = curr_str + rv;
            ind1--;
            ind2--;
        }
        while(ind1 > 0){
            int curr = int(num1[ind1-1]) + carry - 48;
            carry = curr/10;
            char curr_str = char(curr%10 + 48);
            rv = curr_str + rv;
            ind1--;
        }
        while(ind2 > 0){
            int curr = int(num2[ind2-1]) + carry - 48;
            carry = curr/10;
            char curr_str = char(curr%10 + 48);
            rv = curr_str + rv;
            ind2--;
        }
        if(carry != 0){
            char carry_str = char(carry + 48);
            rv = carry_str + rv;
        }
        return rv;
    }
};

int main(){
    Solution s;
    cout << s.addStrings("1", "1") << endl;
    cout << s.addStrings("11", "129") << endl;
    cout << s.addStrings("23121", "5641") << endl;
}