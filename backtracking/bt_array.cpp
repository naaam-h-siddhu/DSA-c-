#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fr first
#define sc second
#define srt(a) sort((a).begin(),(a).end());
#define dsrt(a) sort((a).begin(),(a).end(),greater<>())
void fillarr(int *arr,int i, int n,int val){//here array is passed by reference
	if(i==n){
		for (int j = 0; j < n; ++j)
		{
			cout<<arr[j]<<" ";
		}
		cout<<endl;
		return;

	}
	arr[i]= val;
	fillarr(arr,i+1,n,val+1);
	arr[i]=-1*arr[i];

}
void fillvector(vector<int> &arr,int i, int n,int val){
	if(i==n){
		for (int j = 0; j < n; ++j)
		{
			cout<<arr[j]<<" ";
		}
		cout<<endl;
		return;
	}
	arr[i]=val;
	fillvector(arr,i+1,n,val+1);
	arr[i]=-1*arr[i];

}

int main(){
	vector<int> arr(100,0);
	int n;
	cin>>n;
	fillvector(arr,0,n,1);
	for (int i = 0; i < n; ++i)
	{
		cout<<arr[i]<<" ";
	}

	return 0;
}