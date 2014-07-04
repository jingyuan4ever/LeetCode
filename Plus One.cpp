#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int carry=0;
        int add=1;
        for(auto it=digits.rbegin();it!=digits.rend();it++)
        {
            *it+=carry+add;
            if(*it==10){
                *it=0;
                carry=1;
            }else{
                carry=0;
            }
            add=0;
        }
        if(carry==1){
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};