//print the count of all the subs with the given sum
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fr first
#define sc second
#define srt(a) sort((a).begin(),(a).end());
#define dsrt(a) sort((a).begin(),(a).end(),greater<>())

int summer(int ind, vector<int> ds,int s, int sum, int arr[],int n){
	//base case
	if(ind == n){
		//check weather the subsequence sum is equal to the given sum
		if(s == sum){
			return 1;
		}
		return 0;
	}
	//take
	ds.push_back(arr[ind]);
	s += arr[ind];

	int l = summer(ind+1,ds,s,sum,arr,n);

	//not take
	s -= arr[ind];
	ds.pop_back();
	int r = summer(ind+1,ds,s,sum,arr,n);
	return l+r;
}

int main(){
	cout<<"enter the size of array"<<endl;
	int n;cin>>n;
	int arr[n];
	cout<<"enter the elements of arrat"<<endl;
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
	vector<int> ds;
	cout<<"enter the sum "<<endl;
	int sum;cin>>sum;
	summer(0,ds,0,sum,arr,n);
	return 0;
}