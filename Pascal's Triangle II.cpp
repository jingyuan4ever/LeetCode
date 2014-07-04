#include <vector>
using namespace std;
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ret;
        for(int i=0;i<=rowIndex;i++){
            ret.push_back(1);
            int n=ret.size();
            for(int j=n-2;j>0;j--){
                ret[j]+=ret[j-1];
            }
        }
        return ret;
    }
};