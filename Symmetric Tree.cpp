
#include <stdlib.h>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    bool helper(TreeNode* left, TreeNode* right){
        if(left==nullptr&&right==nullptr){
            return true;
        }
        if(left==nullptr||right==nullptr){
            return false;
        }
        if(left->val==right->val){
            return helper(left->left, right->right)&&helper(left->right, right->left);
        }
        return false;
    }
public:
    bool isSymmetric(TreeNode *root) {
        if(root==nullptr){
            return true;
        }
        return helper(root->left, root->right);
    }
};