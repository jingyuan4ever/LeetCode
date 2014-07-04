#include <vector>
using namespace std;
class Solution {
private:
    vector<vector<int>> ret;
    void helper(vector<int> &num, int start, int end){
        if(start==end){
            ret.push_back(num);
        }
        else{
            for(int i=start;i<end;i++){
                swap(num[start], num[i]);
                helper(num, start+1, end);
                swap(num[start], num[i]);
            }
        }
    }
public:
    vector<vector<int> > permute(vector<int> &num) {
        helper(num, 0, num.size());
        return ret;
    }
};