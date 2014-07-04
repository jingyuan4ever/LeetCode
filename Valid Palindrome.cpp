#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        auto i=s.begin();
        auto j=s.end()-1;
        while(i<j){
            while(!isalnum(*i)&&i<s.end())
                i++;
            while(!isalnum(*j)&&j>=s.begin())
                j--;
            if(i==s.end()||j==s.begin()-1){
                break;
            }
            if(tolower(*i)!=tolower(*j))
                return false;
            i++;
            j--;
        }
        return true;
    }
};