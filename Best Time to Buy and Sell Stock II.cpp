#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.size()==0){
            return 0;
        }
        int ret=0;
        for(auto it=prices.begin()+1;it!=prices.end();it++){
            if(*it>*(it-1)){
                ret+=*it-*(it-1);
            }
        }
        return ret;
    }
};