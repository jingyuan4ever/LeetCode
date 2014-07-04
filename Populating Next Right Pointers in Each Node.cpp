#include <vector>
#include <queue>
using namespace std;


struct TreeLinkNode{
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

struct Node{
	TreeLinkNode *p;
	int level;
	Node(TreeLinkNode *a, int l) : p(a), level(l){}
};

class Solution {
public:
	void connect(TreeLinkNode *root) {
		if (!root)
			return;
		if (!(root->left) && !(root->right)){
			root->next = NULL;
			return;
		}
		queue<Node> s;
		Node pre(root, 0);
		if (root->left){
			s.push(Node(root->left, 1));
		}
		if (root->right){
			s.push(Node(root->right, 1));
		}
		while (!(s.empty())){
			Node now = s.front();
			s.pop();
			if (now.level == pre.level){
				pre.p->next = now.p;
			}
			else{
				pre.p->next = NULL;
			}
			if (now.p->left){
				s.push(Node(now.p->left, now.level + 1));
			}
			if (now.p->right){
				s.push(Node(now.p->right, now.level + 1));
			}
			pre = now;
		}
	}
};