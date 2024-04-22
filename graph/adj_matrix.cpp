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
	vector<vector<int>> arr(n+1,vector<int>(m+1,0));
	for (int i = 0; i < m; ++i)
	{
		int u,v;
		cin>>u>>v;
		arr[u][v]=1;
		arr[v][u]=1;
	}
	return 0;
}
/*
	SPACE COMPLEXITY - O(n*n)
*/