#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fr first
#define sc second
#define srt(a) sort((a).begin(),(a).end());
#define dsrt(a) sort((a).begin(),(a).end(),greater<>())


int main(){
	int n,m;
	cin>>n>>m;
	vector<int> arr[m+1];
	for (int i = 0; i < m; ++i)
	{
		int u,v;
		cin>>u>>v;
		if(n)
		arr[u].push_back(v);
		arr[v].push_back(u);
	}
	//space compl. = O(2e)
	return 0;
}