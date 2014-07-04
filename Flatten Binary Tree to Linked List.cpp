#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void flatten(TreeNode *root) {
        if(!root)
            return;
        stack<TreeNode*> s;
        s.push(root);
        TreeNode* pre=root;
        while(!(s.empty())){
            TreeNode* now = s.top();
            s.pop();
            if(now->right!=nullptr){
                s.push(now->right);
            }
            if(now->left!=nullptr){
                s.push(now->left);
            }
            pre->left=nullptr;
            pre->right=now;
            pre=now;
        }
        pre->right=nullptr;
        return;
    }
};