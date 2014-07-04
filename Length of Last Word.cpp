#include <string>
using namespace std;
class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int ret=0;
        int count=0;
        int i=0;
        while(s[i]){
            if(isalpha(s[i])){
                count++;
            }else{
                if(count!=0)
                    ret=count;
                count=0;
            }
            i++;
        }
        if(count!=0)
            ret=count;
        return ret;
    }
};