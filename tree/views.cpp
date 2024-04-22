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
	vector<int> rightview;
	Node* right;
	Node(int val){
		data = val;
		left = NULL;
		right = NULL;
	}
	vector<int> topview(Node * root){
		vector<int> ans;
		if(root == NULL) return ans;
		map<int,int> mpp;
		queue<pair<Node *,int>> q;
		q.push({root,0});
		while(!q.empty()){
			auto it = q.front();
			q.pop();
			Node * node = it.first;
			int line = it.second;
			if(mpp.find(line) == mpp.end())
				mpp[line] = node->data;
			if(node->left != NULL){
				q.push({node->left, line-1});

			}
			if(node->right != NULL) 
				q.push({node->right,line+1});
		}
		for(auto it:mpp)
			ans.pb(it.second);
		return ans;		

	}
	vector<int> bottomview(Node * root){
		vector<int> ans;
		if(root == NULL) return ans;
		map<int,int> mpp;
		queue<pair<Node *, int>> q;
		q.push({root,0});
		while(!q.empty()){
			auto it = q.front();
			q.pop();
			Node * node = it.first;
			int line = it.second;
			mpp[line] = node->data;
			if(node ->left != NULL) q.push({node->left,line-1});

			if(node->right != NULL) q.push({node->right, line+1});
		}
		for(auto it:mpp)
			ans.pb(it.second);
		return ans;
	}
	void Rightview(Node * root, int level){
		if(root == NULL) return;
		if(level == rightview.size())
			rightview.push_back(root->data);
		Rightview(root->right,level+1);
		Rightview(root->left, level+1);
		//for left view just place recursive call of left first theen right  rest are same
	}
	
};
int main(){
	
	Node* root = new Node(1);root -> left = new Node(2);root -> right = new Node(3);root -> left -> left = new Node(4);
	root -> left -> right = new Node(5);root -> right -> left = new Node(6);root -> right -> right = new Node(7);
	
	vector<int> topview;
	topview= root->topview(root);
	for(auto it :topview){
		cout<<it<<' ';
	}
	cout<<endl;

	vector<int> bottomview;
	bottomview = root->bottomview(root);
	for(auto it: bottomview){
		cout<<it<<" ";
	}
	cout<<endl;
	root->Rightview(root,0);
	for(auto it:root->rightview)
		cout<<it<<" ";

	




	return 0;
}