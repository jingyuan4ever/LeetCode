#include <vector>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<int> m;
        m.push_back(1);
        for(int i=1;i<=n;i++){
            int tmp=0;
            for(int j=1;j<=i;j++){
                tmp+=m[j-1]*m[i-j];
            }
            m.push_back(tmp);
        }
        return m[n];
    }
};