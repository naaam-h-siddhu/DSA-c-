#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mod 1000000007
#define endl '\n'

int firstocc(int arr[],int n,int key){
	if(n==0)
		return -1;
	if(arr[0]==key)
		return 0;
	int subIndex = firstocc(arr+1,n-1,key);
	if(subIndex!=-1)
		return subIndex+1;
	return -1;
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int arr[]={1,2,4,4,7,6};
	int n=sizeof(arr)/sizeof(int);
	int key =7;
	cout<<firstocc(arr,n,key)<<endl;
	
	
	return 0;
}
