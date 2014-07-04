#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int ret=0;
        int gap=INT_MAX;
        sort(num.begin(), num.end());
        for(int i=0;i<num.size()-2;){
            int a=num[i];
            int remain=target-a;
            int j=i+1;
            int k=num.size()-1;
            while(j<k){
                if(num[j]+num[k]<remain){
                    if(abs(remain-num[j]-num[k])<gap){
                        gap=abs(remain-num[j]-num[k]);
                        ret=num[i]+num[j]+num[k];
                    }
                    do{
                        j++;
                    }while(num[j]==num[j-1]);
                }else if(num[j]+num[k]>remain){
                    if(abs(remain-num[j]-num[k])<gap){
                        gap=abs(remain-num[j]-num[k]);
                        ret=num[i]+num[j]+num[k];
                    }
                    do{
                        k--;
                    }while(num[k]==num[k+1]);
                }else{
                    return target;
                }
            }
            do{
                i++;
            }while(num[i]==num[i-1]);
        }
        return ret;
    }
};