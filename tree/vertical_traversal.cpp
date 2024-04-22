#include<bits/stdc++.h>
#include<set>
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
	vector<vector<int>> vertical_traversal(Node * root){

		map<int,map<int,multiset<int>>> mp;
		queue<pair<Node *, pair<int,int>>> q;
		q.push({root,{0,0}});
		while(!q.empty()){
			auto p = q.front();
			q.pop();
			Node * node = p.first;
			int x = p.second.first;int y = p.second.first;
			mp[x][y].insert(node->data);
			if(node->left){
				q.push({node->left,{x-1,y+1}});
			}
			if(node->right){
				q.push({node->right,{x+1,y+1}});

			}
		}
		vector<vector<int>> ans;
		for(auto it: mp){
			vector<int> col;
			for(auto p: it.second){
				col.insert(col.end,p.second.begin(),p.second.end());

			}
			ans.pb(col);

		}
		return ans;


	}
	
};



int main(){
	
	Node* root = new Node(1);root -> left = new Node(2);root -> right = new Node(3);root -> left -> left = new Node(4);
	root -> left -> right = new Node(5);root -> right -> left = new Node(6);root -> right -> right = new Node(7);
	vector<vector<int>> ans;
	ans= root->vertical_traversal(root);
	for(auto it: ans){
		for(auto a:ans){
			cout<<a<<" ";
		}
		cout<<endl;
	}
	




	return 0;
}