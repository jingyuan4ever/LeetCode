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
    int minDepth(TreeNode *root) {
        queue<pair<TreeNode*, int>> m;
        if(!root)
            return 0;
        m.push(pair<TreeNode*, int>(root, 1));
        while(!m.empty()){
            pair<TreeNode*, int> now(m.front());
            m.pop();
            TreeNode* nn(now.first);
            int height(now.second);
            if(nn->left==nullptr&&nn->right==nullptr)
                return height;
            if(nn->left)
                m.push(pair<TreeNode*, int>(nn->left,height+1));
            if(nn->right)
                m.push(pair<TreeNode*, int>(nn->right,height+1));
        }
        return 0;
    }
};