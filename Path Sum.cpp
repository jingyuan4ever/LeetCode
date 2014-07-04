#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if(!root)
            return false;
        queue<TreeNode*> s;
        s.push(root);
        while(!(s.empty())){
            TreeNode* p=s.front();
            s.pop();
            if(p->left==nullptr&&p->right==nullptr){
                if(p->val==sum){
                    return true;
                }
            }
            if(p->left!=nullptr){
                p->left->val+=p->val;
                s.push(p->left);
            }
            if(p->right!=nullptr){
                p->right->val+=p->val;
                s.push(p->right);
            }
        }
        return false;
    }
};