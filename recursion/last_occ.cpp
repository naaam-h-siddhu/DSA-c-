#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fr first
#define sc second
#define srt(a) sort((a).begin(),(a).end());
#define dsrt(a) sort((a).begin(),(a).end(),greater<>())

int last_occ(int arr[],int n,int key){
	if(n==0)
		return -1;
	if(arr[n-1]==key){
		return n-1;
	}
	int subIndex = last_occ(arr+1,n-1,key);
	if(subIndex==-1){
		if(arr[0]==key)
			return 0;
		else
			return -1;
	}
	else
		return subIndex+1;
	return-1;
}

int main(){
	int arr[]= {1,2,2,2,3,3,4,5};
	int n = sizeof(arr)/sizeof(int);
	int key = 3;
	cout<<last_occ(arr,n,key)<<endl;
	return 0;
}