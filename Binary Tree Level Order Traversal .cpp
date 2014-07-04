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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int>> v;
        vector<TreeNode*> thisLevel({root});
        if(!root){
            return v;
        }
        while(!thisLevel.empty()){
            vector<int> values;
            vector<TreeNode*> nextLevel;
            for(auto it=thisLevel.begin();it!=thisLevel.end();it++){
                values.push_back((*it)->val);
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