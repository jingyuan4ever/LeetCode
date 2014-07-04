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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        int len=num.size();
        if(len==0){
            return nullptr;
        }
        if(len==1){
            return new TreeNode(num[0]);
        }
        int mid=len/2;
        TreeNode *root=new TreeNode(num[mid]);
        vector<int> left(num.begin(), num.begin()+mid);
        vector<int> right(num.begin()+mid+1, num.end());
        root->left=sortedArrayToBST(left);
        root->right=sortedArrayToBST(right);
        return root;
    }
};