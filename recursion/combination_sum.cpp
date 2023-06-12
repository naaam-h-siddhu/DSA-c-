#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fr first
#define sc second
#define srt(a) sort((a).begin(),(a).end());
#define dsrt(a) sort((a).begin(),(a).end(),greater<>())
void csum(int ind,int n ,int arr[],vector<int> ds,int target){
	if(ind == n){
		if(target == 0){
			for(auto it: ds)
				cout<<it<<" ";
			cout<<endl;
		}
		return;
	}
	if(arr[ind]<=target){
		ds.push_back(arr[ind]);
		csum(ind,n,arr,ds, target-arr[ind]);
		ds.pop_back();
	}
	csum(ind+1,n,arr,ds,target);
}
int main(){
	int n;cin>>n;
	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
	int target;cin>>target;
	vector<int> ds;
	csum(0,n,arr,ds,target);
	return 0;
}