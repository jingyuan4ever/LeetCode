#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void recoverTree(TreeNode *root)  {
        TreeNode *p = root, *tmp(0);
        TreeNode *p1(0), *n1(0), *p2(0), *n2(0), *pre(0), *next(0);
        while(p){
            if(p->left==nullptr){
                pre = next;
                next = p;
                if(pre!=nullptr){
                    if(pre->val>next->val){
                        if(p1==nullptr){
                            p1=pre;
                            n1=next;
                        }else{
                            p2=pre;
                            n2=next;
                        }
                    }
                }
                p=p->right;
            }else{
                tmp=p->left;
                while(tmp->right!=nullptr&&tmp->right!=p){
                    tmp=tmp->right;
                }
                if(tmp->right==nullptr){
                    tmp->right=p;
                    p=p->left;
                }else{
                    pre = next;
                    next = p;
                    if(pre!=nullptr){
                        if(pre->val>next->val){
                            if(p1==nullptr){
                                p1=pre;
                                n1=next;
                            }else{
                                p2=pre;
                                n2=next;
                            }
                        }
                    }
                    tmp->right=nullptr;
                    p=p->right;
                }
            }
        }
        if(p2==nullptr){
            swap(p1->val, n1->val);
        }else{
            swap(p1->val, n2->val);
        }
    }
};