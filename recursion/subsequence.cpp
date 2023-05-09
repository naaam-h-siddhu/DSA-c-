#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fr first
#define sc second
#define srt(a) sort((a).begin(),(a).end());
#define dsrt(a) sort((a).begin(),(a).end(),greater<>())
void subs(int ind, vector<int> &ds, int arr[], int n){
	if(ind == n){
		for(auto it: ds){
			cout<<it<<" ";

		}
		cout<<endl;
		return;
	}

	//take or pick the particular index into the subsequence
	ds.pb(arr[ind]);
	subs(ind+1,ds, arr, n);
	//not take the particular index into the subsequence
	ds.pop_back();
	subs(ind+1,ds,arr,n);
}
int main(){
	int arr[] = {3,1,2};
	int n = 3;
	vector<int> ds;
	subs(0,ds,arr,n);
	return 0;
}