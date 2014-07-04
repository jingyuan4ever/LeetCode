#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> v;
        vector<TreeNode*> thisLevel({root});
        if(!root){
            return v;
        }
        int i=0;
        while(!thisLevel.empty()){
            i++;
            vector<int> values;
            vector<TreeNode*> nextLevel;
            if(i%2){
                for(auto it=thisLevel.begin();it!=thisLevel.end();it++){
                    values.push_back((*it)->val);
                }
            }else{
                for(auto it=thisLevel.rbegin();it!=thisLevel.rend();it++){
                    values.push_back((*it)->val);
                }
            }
            for(auto it=thisLevel.begin();it!=thisLevel.end();it++){
                if((*it)->left!=nullptr){
                    nextLevel.push_back((*it)->left);
                }
                if((*it)->right!=nullptr){
                    nextLevel.push_back((*it)->right);
                }
            }
            v.push_back(values);
            thisLevel=nextLevel;
        }
        return v;
    }
};