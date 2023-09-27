#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fr first
#define sc second
#define srt(a) sort((a).begin(),(a).end());
#define dsrt(a) sort((a).begin(),(a).end(),greater<>())
class graph{
	int V;
	vector<vector<int>> arr;
public:
	
	graph(int V){
		this->V = V;
		arr.resize(V);
	}
	void coder(int start,vector<int> &vis,vector<int> &ls){
		vis[start] = 1;
		ls.pb(start);
		for(auto it:arr[start]){
			if(!vis[it]){
				coder(it,vis,ls);
			}
			else
				vis[it]++;
		}
	}
	void addEdge(int u, int v){
		arr[u].pb(v);
		arr[v].pb(u);
	}
	vector<int> dfs(int n,int starting_node){
		vector<int> vis(n+1);
		int start = starting_node;
		vector<int> ls;
		coder(start,vis,ls);
		cout<<"visited array  = ";
		for(auto it:vis){
			cout<<it<<" ";
		}
		cout<<endl;
		return ls;
	}

};
int main(){
	int n;
	cin>>n;
	graph g(n);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    int x;
    cin>>x;
    vector<int> ans;

    ans = g.dfs(n,x);
    for(auto it:ans){
    	cout<<it<<" ";
    }
    cout<<endl;

	
	return 0;
}