#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int>> ret;
        if(num.size()<3)
            return ret;
        sort(num.begin(), num.end());
        for(int i=0;i<num.size()-2;){
            int a=num[i];
            int target=-a;
            int j=i+1;
            int k=num.size()-1;
            while(j<k){
                if(num[j]+num[k]<target){
                    do{
                        j++;
                    }while(num[j]==num[j-1]);
                }else if(num[j]+num[k]>target){
                    do{
                        k--;
                    }while(num[k]==num[k+1]);
                }else{
                    ret.push_back(vector<int>({num[i],num[j],num[k]}));
                    do{
                        j++;
                    }while(num[j]==num[j-1]);
                    do{
                        k--;
                    }while(num[k]==num[k+1]);
                }
            }
            do{
                i++;
            }while(num[i]==num[i-1]);
        }
        return ret;
    }
};