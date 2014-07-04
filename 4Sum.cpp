#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int>> ret;
        if(num.size()<4)
            return ret;
        sort(num.begin(), num.end());
        for(int i=0;i<num.size()-3;){
            for(int l=i+1;l<num.size()-2;){
                int a=num[i];
                int b=num[l];
                int remain=target-a-b;
                int j=l+1;
                int k=num.size()-1;
                while(j<k){
                    if(num[j]+num[k]<remain){
                        do{
                            j++;
                        }while(num[j]==num[j-1]);
                    }else if(num[j]+num[k]>remain){
                        do{
                            k--;
                        }while(num[k]==num[k+1]);
                    }else{
                        ret.push_back(vector<int>({num[i],num[l],num[j],num[k]}));
                        do{
                            j++;
                        }while(num[j]==num[j-1]);
                        do{
                            k--;
                        }while(num[k]==num[k+1]);
                    }
                }
                do{
                    l++;
                }while(num[l]==num[l-1]);
            }
            do{
                i++;
            }while(num[i]==num[i-1]);
        }
        return ret;
    }
};