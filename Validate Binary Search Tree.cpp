#include <limits>
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
    bool isValidBST(TreeNode *root) {
        TreeNode* now=root;
        int pre=INT_MIN;
        vector<TreeNode*> stack;
        stack.push_back(root);
        while(!stack.empty()){
            while(stack.back()!=nullptr){
                stack.push_back(now->left);
                now=now->left;
            }
            stack.pop_back();
            if(!stack.empty()){
                if(stack.back()->val>pre){
                    pre=stack.back()->val;
                    now=stack.back()->right;
                    stack.pop_back();
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};