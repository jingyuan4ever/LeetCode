#include <string>
#include <unordered_set>
#include <vector>
#include <iostream>
using namespace std;
class Solution {
private:
    vector<vector<int>> arr;
    bool innerWordBreak(string s, int start, int end, unordered_set<string> &dict){
        if(arr[start][end]==1){
            return true;
        }
        if(arr[start][end]==2){
            return false;
        }
        string tmp = s.substr(start);
        if(dict.find(tmp)!=dict.end()){
            arr[start][end] = 1;
            return true;
        }
        
        for(int i=start+1;i<=end;i++){
            tmp = s.substr(start, i-start);
            if(dict.find(tmp)!=dict.end()){
                if(innerWordBreak(s, i, end, dict)){
                    arr[start][end]=1;
                    return true;
                }
            }
        }
        arr[start][end]=2;
        return false;
    }
    
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        int l = s.length();
        for(int i=0;i<l;i++){
            arr.push_back(vector<int>(l));
        }
        return innerWordBreak(s, 0, l-1, dict);
    }
};