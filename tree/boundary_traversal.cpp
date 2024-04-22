#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fr first
#define sc second
#define srt(a) sort((a).begin(),(a).end());
#define dsrt(a) sort((a).begin(),(a).end(),greater<>())
#define endl "\n"
class Node{
private:
	bool isleaf(Node * root){
		return (root->left == NULL and root->right == NULL);
	}
	//only left excluding leaf node
	void addleft(Node * root,vector<int> &ans){
		Node* cur = root->left;
		while(cur){
			if(!isleaf(cur)) ans.pb(cur->data);
			if(cur->left) cur = cur->left;
			else cur = cur->right;

		}
	}
	void addright(Node * root, vector<int> &ans){
		Node * cur = root->right;
		vector<int> tmp;
		while(cur){
			if(!isleaf(cur)) tmp.pb(cur->data);
			if(cur->right) cur=cur->right;
			else cur=cur->left;
		}
		for(int i = tmp.size()-1;i>=0;i--){
			ans.pb(tmp[i]);
		}

	}
	void addleaf(Node * root, vector<int> &ans){
		if(isleaf(root)){
			ans.pb(root->data);
			return;

		}
		if(root->left) addleaf(root->left,ans);
		if(root->right) addleaf(root->right,ans);
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
	vector<int> printBoundary(Node * root){
		vector<int> ans;
		if(!root) return ans;
		if(!isleaf(root)) ans.pb(root->data);
		addleft(root,ans);
		addleaf(root,ans);
		addright(root,ans);
		return ans;
	}
};



int main(){
	
	Node* root = new Node(1);root -> left = new Node(2);root -> right = new Node(3);root -> left -> left = new Node(4);
	root -> left -> right = new Node(5);root -> right -> left = new Node(6);root -> right -> right = new Node(7);
	vector<int> ans;
	ans = root->printBoundary(root);
	for(auto it: ans) cout<<it<<" ";




	return 0;
}