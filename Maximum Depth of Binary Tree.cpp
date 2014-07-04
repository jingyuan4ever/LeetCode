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
    int maxDepth(TreeNode *root) {
        if(!root)
            return 0;
        int height=0;
        queue<pair<TreeNode*, int>> q;
        q.push(pair<TreeNode*, int>(root,1));
        while(!(q.empty())){
            pair<TreeNode*, int> p=q.front();
            q.pop();
            TreeNode* t = p.first;
            height=p.second;
            if(t->left!=nullptr){
                q.push(pair<TreeNode*, int>(t->left, height+1));
            }
            if(t->right!=nullptr){
                q.push(pair<TreeNode*, int>(t->right, height+1));
            }
        }
        return height;
    }
};