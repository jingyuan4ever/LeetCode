#include <algorithm>
#include <stdlib.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    int balanceHeight(TreeNode *root) {
        if(!root){
            return 0;
        }
        int leftHeight=balanceHeight(root->left);
        int rightHeight=balanceHeight(root->right);
        if(leftHeight==-1||rightHeight==-1)
            return -1;
        if(abs(leftHeight-rightHeight)>1)
            return -1;
        else
            return max(leftHeight,rightHeight)+1;
    }
public:
    bool isBalanced(TreeNode *root) {
        if(balanceHeight(root)==-1)
            return false;
        return true;
    }
};