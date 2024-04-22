#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fr first
#define sc second
#define srt(a) sort((a).begin(),(a).end());
#define dsrt(a) sort((a).begin(),(a).end(),greater<>())
#define endl "\n"


// representation of tree usign class 
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
};
void preorder(Node *node){
		if(node == NULL)
			return;
		cout<<node->data<<" ";
		preorder(node->left); 
}
void inorder(Node *node){
	if(node == NULL)
		return;
	inorder(node->left);
	cout<<node->data<<" ";
	inorder(node->right); 
}
void postorder(Node *node){
	if(node == NULL)
		return;
	postorder(node->left);
	postorder(node-> right);
	cout<<node->data<<" ";
}
void level_order(Node *root){
	queue<Node *> q;
	q.push(root);
	while(!q.empty()){
		Node *node = q.front();
		if(node->left !=NULL)
			q.push(node->left);
		if(node->right !=NULL)
			q.push(node->right);
		cout<<node->data<<" ";
		q.pop();
	}
}
void itr_preorder(Node *root){
	stack<Node *> st;
	st.push(root);
	while(!st.empty()){
		root = st.top();
		st.pop();
		cout<<root->data<<" ";
		if(root->right !=NULL){
			st.push(root->right);

		}
		if(root->left != NULL){
			st.push(root->left);
		}
	}
}
void itr_inorder(Node *root){
	stack<Node *> st;
	// Node *node = root;
	while(1){
		if(root != NULL){
			st.push(root);
			root = root->left;
		}
		else{
			if(st.empty()) break;
			root = st.top();
			st.pop();
			cout<<root->data<<" ";
			root = root->right;

		}
	}
}
void itr_postorder2st(Node * root){
	if(root == NULL) return;
	stack<Node *> st1,st2;
	st1.push(root);
	while(!st1.empty()){
		root = st1.top();
		st1.pop();
		st2.push(root);
		if(root->left != NULL)
			st1.push(root->left);
		if(root->right != NULL)
			st1.push(root->right);

	}
	while(!st2.empty()){
		cout<<st2.top()->data<<" ";
		st2.pop();
	}
}


void prints(vector<int> arr){
	for(auto it:arr)
		cout<<it<<" ";
	cout<<endl;
}

//inorder, preorder, postorder in a single function
void allinone(Node * root){
	stack<pair<Node *, int>> st;
	st.push({root,1});
	vector<int> pre,in,post;
	if(root == NULL) return;
	while(!st.empty()){
		auto it = st.top();
		st.pop();
		if(it.second == 1){
			pre.push_back(it.first->data);
			it.second++;
			st.push(it);
			if(it.first->left != NULL)
				st.push({it.first-> left,1});


		}
		else if(it.second==2){
			in.push_back(it.first->data);
			it.second++;
			st.push(it);
			if(it.first-> right !=NULL){
				st.push({it.first->right, 1});

			}
		}
		else{
			post.push_back(it.first->data);
		}
	}
	cout<<"inorder ";
	prints(in);
	cout<<"postorder ";
	prints(post);
	cout<<"preorder ";
	prints(pre);
}
//depth/Height of the binary tree
int height(Node * root){
	if(root == NULL) return 0;
	int lh = height(root->left);
	int rh = height(root->right);
	return 1+max(lh,rh);

}
//check if the Binary tree is Balanced or not
int Bheight(Node * root){
	if(root== NULL) return 0;
	int lh = Bheight(root->left);
	if(lh == -1) return -1;
	int rh = Bheight(root->right);
	if(rh == -1) return -1;
	if(abs(lh-rh) >1 ) return -1;
	return max(lh,rh)+1;
}
bool isBalanced(Node * root){
	return Bheight(root) !=1;
}




// Diameter of the Binary Tree 

int Diameterheight(Node * root, int diameter){
	if(root == NULL) return 0;
	int lh = Diameterheight(root->left,diameter);
	int rh = Diameterheight(root->right,diameter);


	diameter = max(diameter,lh+rh);
	return 1+max(lh,rh);
}
int diameterofBT(Node * root){
	int dia = 0;
	Diameterheight(root,dia);
	return dia;
}

// Maximum path sum problem
int maxpathDown(Node * root, int &maxi){
	if(root == NULL) return 0;
	int left = max(0,maxpathDown(root-> left, maxi));
	int right = max(0, maxpathDown(root->right,maxi));
	maxi = max(maxi,left+right+root->data);
	return max(left,right)+root->data;



}
int maxPathSum(Node *root){
	int maxi = INT_MIN;
	maxpathDown(root,maxi);
	return maxi;
}

//check if two tree are same or not
bool isSame(Node * p,Node * q){
	if(p ==NULL or q == NULL)
		 return p==q;
	return (p->data == q->data) and isSame(p->left,q->left) and isSame(p->right,q->right); 
}



//zig-zag/ spiral traversal of BT
void zigzag(Node* root){

	if(root == NULL) return;
	queue<Node *> q;
	q.push(root);
	bool flag = true;

	while(!q.empty()){
		int size = q.size(); vector<int> row(size);
		for(int i =0;i<size;i++){
			Node * node = q.front();
			q.pop();
			int it = (flag) ? i: (size-1-i);
			row[it] = node->data;
			if(node->left != NULL){
				q.push(node->left);

			}
			if(node->right != NULL){
				q.push(node->right);

			}
		}
		flag = !flag;
		prints(row);
	}
}

int main(){
	
	Node* root = new Node(1);
	root -> left = new Node(2);
	root -> right = new Node(3);
	root -> left -> left = new Node(4);
	root -> left -> right = new Node(5);
	root -> right -> left = new Node(6);
	root -> right -> right = new Node(7);
	// cout<<"preorder traversal is : ";
	// preorder(root);
	// cout<<endl<<"inorder traversal is :";
	// inorder(root);
	// cout<<endl<<"postorder traversal is : ";
	// postorder(root);
	// cout<<endl<<"level_order traversal is: ";
	// level_order(root);
	// cout<<endl<<"iterative preorder is : ";
	// itr_preorder(root);
	// cout<<endl<<"iterative inorder is :";
	// itr_inorder(root);
	// cout<<endl<<"iterative 2st postorder is :";
	// itr_postorder2st(root);
	// cout<<"height of the BT = "<<height(root);
	// allinone(root);
	cout<<"balanced or not = "<<isBalanced(root)<<endl;
	cout<<"Diameter of th BT is "<<diameterofBT(root)<<endl;
	cout<<"Max path sum of the BT is "<<maxPathSum(root)<<endl;
	// Node * root2 = new Node(1);
	// root2 -> left = new Node(2);
	// root2 -> right = new Node(3);
	// root2 -> left -> left = new Node(4);
	// root2 -> left -> right = new Node(5);
	// root2 -> right -> left = new Node(6);
	// root2 -> right -> right = new Node(0);
	// cout<<"is same or not"<<isSame(root,root2)? "true":"false";
	zigzag(root);
	return 0;
}