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
    int sumNumbers(TreeNode *root) {
        if(!root)
            return 0;
        int sum=0;
        queue<TreeNode *> q;
        q.push(root);
        while(!(q.empty())){
            TreeNode* t = q.front();
            q.pop();
            if(t->left==nullptr&&t->right==nullptr){
                sum+=t->val;
            }else{
                if(t->left!=nullptr){
                    t->left->val+=t->val*10;
                    q.push(t->left);
                }
                if(t->right!=nullptr){
                    t->right->val+=t->val*10;
                    q.push(t->right);
                }
            }
        }
        return sum;
    }
};