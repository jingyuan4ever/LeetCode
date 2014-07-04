#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    TreeNode* helper(vector<int> &preorder, vector<int> &inorder, int pstart, int pend, int istart, int iend){
        if((pend-pstart)<1){
            return nullptr;
        }
        int value=preorder[pstart];
        TreeNode *n = new TreeNode(value);
        int imid;
        
        for(imid=istart;imid!=iend;imid++){
            if(inorder[imid]==value)
                break;
        }
        int pmid=pstart+1+imid-istart;
        n->left=helper(preorder, inorder, pstart+1, pmid, istart, imid);
        n->right=helper(preorder, inorder, pmid, pend, imid+1, iend);
        return n;
    }
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return helper(preorder, inorder, 0, preorder.size(), 0, inorder.size());
    }
};