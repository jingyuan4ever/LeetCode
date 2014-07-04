#include <string>
#include <vector>
using namespace std;

class Solution {
private:
    int factorial(int n){
        int ret=1;
        for(int i=1;i<=n;i++){
            ret*=i;
        }
        return ret;
    }
public:
    string getPermutation(int n, int k) {
        k--;
        vector<char> candidate;
        string ret;
        for(int i=0;i<n;i++){
            candidate.push_back('1'+i);
        }
        for(int i=n-1;i>0;i--){
            int f = factorial(i);
            int j = k/f;
            k%=f;
            ret.push_back(candidate[j]);
            candidate.erase(candidate.begin()+j);
        }
        ret.push_back(candidate[0]);
        return ret;
    }
};