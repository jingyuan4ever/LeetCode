#include <string>
#include <stack>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> ss;
        for(auto it=s.begin();it!=s.end();it++){
            if(*it=='('||*it=='['||*it=='{'){
                ss.push(*it);
            }
            if(*it==')'){
                if(!ss.empty()&&ss.top()=='('){
                    ss.pop();
                }else{
                    return false;
                }
            }
            if(*it==']'){
                if(!ss.empty()&&ss.top()=='['){
                    ss.pop();
                }else{
                    return false;
                }
            }
            if(*it=='}'){
                if(!ss.empty()&&ss.top()=='{'){
                    ss.pop();
                }else{
                    return false;
                }
            }
        }
        if(ss.empty())
            return true;
        return false;
    }
};