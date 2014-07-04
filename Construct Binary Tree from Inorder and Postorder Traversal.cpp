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
    TreeNode *helper(vector<int> &inorder, vector<int> &postorder, int instart, int inend, int pstart, int pend){
        if((pend-pstart)<1){
            return nullptr;
        }
        int value=postorder[pend-1];
        TreeNode* n=new TreeNode(value);
        int inmid;
        for(inmid=instart;inmid!=inend;inmid++){
            if(inorder[inmid]==value)
                break;
        }
        int pmid=inmid-instart+pstart;
        n->left=helper(inorder, postorder, instart, inmid, pstart, pmid);
        n->right=helper(inorder, postorder, inmid+1, inend, pmid, pend-1);
        return n;
    }
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return helper(inorder, postorder, 0, inorder.size(), 0, postorder.size());
    }
};