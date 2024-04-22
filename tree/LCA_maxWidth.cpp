#include<bits/stdc++.h>
#include<map>
using namespace std;
#define ll long long
#define pb push_back
#define fr first
#define sc second
#define srt(a) sort((a).begin(),(a).end());
#define dsrt(a) sort((a).begin(),(a).end(),greater<>())
#define endl "\n"
class Node{
	
public:
	int data;
	Node* left;
	Node* right;
	Node(int val){
		data = val;
		left = NULL;
		right = NULL;
	}

	Node * lowest(Node * root, Node * p,Node* q){
		if(root==NULL or root==p or root==q)
			return root;
		Node * left = lowest(root->left, p,q);
		Node * right = lowest(root->right,p,q);

		 if(left == NULL) return right;
		 else if(right == NULL) return left;
		 else return root;
	}
	int widtthofBt(Node * root){
		if(!root) return 0;
		int ans = 0;
		queue<pair<Node *, int>> q;
		q.push({root,0});
		while(!q.empty()){
			int size = q.size();
			int mmin = q.front().second;
			int first, last;
			for(int i = 0;i<size;i++){
				int cur_id = q.front().second -mmin;
				Node * node = q.front().first;
				q.pop();
				if(i ==0) first =cur_id;
				if( i == size-1) last = cur_id;
				if(node->left)
					q.push({node->left, cur_id*2+1});
				if(node->right)
					q.push({node->right, cur_id*2+2});
			}
			ans = max(ans, last-first+1);
		}
		return ans;

	}
};
int main(){
	
	Node* root = new Node(1);root -> left = new Node(2);root -> right = new Node(2);root -> left -> left = new Node(4);
	root -> left -> right = new Node(5);root -> right -> left = new Node(5);root -> right -> right = new Node(4);

	

	return 0;
}