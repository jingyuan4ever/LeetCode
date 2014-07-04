#include <stack>
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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> ret;
        stack<TreeNode*> s;
        s.push(root);
        while(!(s.empty())){
            while(s.top()!=nullptr){
                TreeNode* t = s.top();
                s.push(t->left);
                t=t->left;
            }
            s.pop();
            if(!(s.empty())){
                TreeNode *t=s.top();
                s.pop();
                ret.push_back(t->val);
                s.push(t->right);
            }
        }
        return ret;
    }
};