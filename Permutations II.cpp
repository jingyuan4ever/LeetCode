#include <vector>
using namespace std;

class Solution {
private:
    bool isOK(vector<int> &num, int x, int y){
        if(x<y){
            for(int i = x ;i<y;i++){
                if(num[i]==num[y])
                    return false;
            }
        }
        return true;
    }
    vector<vector<int>> ret;
    void helper(vector<int> &num, int start, int end){
        if(start==end){
            ret.push_back(num);
        }
        
        else{
            for(int i=start;i<end;i++){
                if(isOK(num, start, i)){
                    swap(num[start], num[i]);
                    helper(num, start+1, end);
                    swap(num[start], num[i]);
                }
            }
        }
    }
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        helper(num, 0, num.size());
        return ret;
    }
};