#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct Node{
    vector<int> path;
    TreeNode* tn;
    int sum;
    Node(vector<int> p, TreeNode* t, int s){
        path=p;
        tn=t;
        sum=s;
    }
};

class Solution {
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int>> ret;
        if(!root)
            return ret;
        queue<Node> s;
        Node n(vector<int>(),root, 0);
        s.push(n);
        while(!(s.empty())){
            Node p=s.front();
            s.pop();
            p.path.push_back(p.tn->val);
            p.sum+=p.tn->val;
            if(p.tn->left==nullptr&&p.tn->right==nullptr){
                if(p.sum==sum){
                    ret.push_back(p.path);
                }
            }
            if(p.tn->left!=nullptr){
                s.push(Node(p.path, p.tn->left, p.sum));
            }
            if(p.tn->right!=nullptr){
                s.push(Node(p.path, p.tn->right, p.sum));
            }
        }
        return ret;
    }
};