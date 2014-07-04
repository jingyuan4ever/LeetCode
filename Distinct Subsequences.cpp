#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    int numDistinct(string S, string T) {
        int sLen = S.length();
        int tLen = T.length();
        vector<vector<int>> tab;
        tab.push_back(vector<int>(sLen+1, 1));
        for(int i=0;i<tLen;i++){
            tab.push_back(vector<int>(sLen+1, 0));
        }
        for(int i=1;i<=tLen;i++){
            for(int j=i;j<=sLen;j++){
                tab[i][j]=tab[i][j-1];
                if(S[j-1]==T[i-1]){
                    tab[i][j]+=tab[i-1][j-1];
                }
            }
        }
        return tab[tLen][sLen];
    }
};