#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int>> ret;
        if(numRows==0)
            return ret;
        
        vector<int> row={1};
        ret.push_back(row);
        for(int i=1;i<numRows;i++){
            row.clear();
            row.push_back(1);
            for(int j=1;j<i;j++){
                row.push_back(ret[i-1][j-1]+ret[i-1][j]);
            }
            row.push_back(1);
            ret.push_back(row);
        }
        return ret;
    }
};