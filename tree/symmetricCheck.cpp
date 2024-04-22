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
	bool issym(Node* left,Node* right){
		if(left == NULL or right == NULL)
			return left == right;
		if(left->data != right->data) return false;
		return issym(left->left,right->right) and issym(left->right,right->left);
	}
public:
	int data;
	Node* left;
	Node* right;
	Node(int val){
		data = val;
		left = NULL;
		right = NULL;
	}

	bool isSymmetric(Node * root){
		return root==NULL or issym(root->left, root->right);

	}
	
};
int main(){
	
	Node* root = new Node(1);root -> left = new Node(2);root -> right = new Node(2);root -> left -> left = new Node(4);
	root -> left -> right = new Node(5);root -> right -> left = new Node(5);root -> right -> right = new Node(4);
	
	cout<<"is the BT symmetric "<<root->isSymmetric(root);


	return 0;
}