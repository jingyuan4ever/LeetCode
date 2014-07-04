#include <stdlib.h>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        if(!head){
            return nullptr;
        }
        if(head->next==nullptr){
            return new TreeNode(head->val);
        }
        ListNode *slow=head, *fast=head, *pre(0);
        while(fast->next!=nullptr&&fast->next->next!=nullptr){
            pre=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        TreeNode *root=new TreeNode(slow->val);
        if(pre!=nullptr){
            pre->next=nullptr;
            root->left=sortedListToBST(head);
        }
        root->right=sortedListToBST(slow->next);
        return root;
    }
};