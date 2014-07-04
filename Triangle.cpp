#include <vector>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int n=triangle.size();
        for(int i=1;i<n;i++){
            for(int j=0;j<=i;j++){
                if(j==0){
                    triangle[i][j]+=triangle[i-1][j];
                }
                else if(j==i){
                    triangle[i][j]+=triangle[i-1][j-1];
                }else{
                    triangle[i][j]+=triangle[i-1][j]>triangle[i-1][j-1]?triangle[i-1][j-1]:triangle[i-1][j];
                }
            }
        }
        int ret=triangle[n][0];
        for(int i=1;i<n;i++){
            if(triangle[n][i]<ret)
                ret=triangle[n][i];
        }
        return ret;
    }
};