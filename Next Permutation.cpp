#include <vector>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int> &num) {
        auto first=num.begin();
        auto last =num.end();
        if(first==last)
            return;
        
        auto i=first;
        ++i;
        if(i==last)
            return;
        
        i=last;
        i--;
        
        for(;;){
            auto ii=i;
            i--;
            if(*i<*ii){
                auto j=last;
                while(!(*i<*--j));
                iter_swap(i, j);
                reverse(ii, last);
                return;
            }
            
            if(i==first){
                reverse(first, last);
                return;
            }
        }
    }
};