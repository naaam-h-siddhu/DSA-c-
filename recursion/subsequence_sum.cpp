#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fr first
#define sc second
#define srt(a) sort((a).begin(),(a).end());
#define dsrt(a) sort((a).begin(),(a).end(),greater<>())

// void summer(int ind, vector<int> ds,int s, int sum, int arr[],int n){
// 	//base case
// 	if(ind == n){
// 		//check weather the subsequence sum is equal to the given sum
// 		if(s == sum){
// 			for(auto it: ds)
// 				cout<<it<<" ";
// 			cout<<endl;
// 		}
// 		return;
// 	}
// 	//take
// 	ds.push_back(arr[ind]);
// 	s += arr[ind];
// 	summer(ind+1,ds,s,sum,arr,n);

// 	//not take
// 	s -= arr[ind];
// 	ds.pop_back();
// 	summer(ind+1,ds,s,sum,arr,n);
// }
bool summer(int ind, vector<int> ds,int s, int sum, int arr[],int n){
	//base case
	if(ind == n){
		//check weather the subsequence sum is equal to the given sum
		if(s == sum){
			for(auto it: ds)
				cout<<it<<" ";
			cout<<endl;
			return true;
		}
		else
			return false;
	}
	//take
	ds.push_back(arr[ind]);
	s += arr[ind];
	if(summer(ind+1,ds,s,sum,arr,n) == true)
		return true;
 
	//not take
	s -= arr[ind];
	ds.pop_back();
	if(summer(ind+1,ds,s,sum,arr,n) == true)
		return true;
	return false;
	
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