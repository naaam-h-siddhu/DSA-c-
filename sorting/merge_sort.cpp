#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fr first
#define sc second
#define srt(a) sort((a).begin(),(a).end());
#define dsrt(a) sort((a).begin(),(a).end(),greater<>())
void merger(vector<int> &arr,int start, int end){
	int i = start;
	int mid = (start + end) /2;
	int j = mid+1;
	vector<int> ans;
	while(i<=mid and j<=end){
		if(arr[i]<arr[j]){
			ans.push_back(arr[i]);
			i++;
		}
		else{
			ans.push_back(arr[j]);
			j++;
		}

	}
	while(i<=mid){
		ans.push_back(arr[i]);
		i++;
	}
	while(j<=end){
		ans.push_back(arr[i]);
		j++;
	}
	int it = 0;
	for(int k =start;k<=end;k++){
		arr[k] = ans[it];
		it++;
	}

}
void sorter(vector<int> &arr,int start,int end){
		if(start>=end)
			return;
		int mid = (start+end)/2;
		sorter(arr,start,mid);
		sorter(arr,mid+1,end);
		return merger(arr,start,end);

}

int main(){
	int n;
	cin>>n;
	std::vector<int> v;
	for (int i = 0; i < n; ++i)
	{
		int it;
		cin>>it;
		v.pb(it);
	}
	int s=0;
	int e=n-1;
	sorter(v,s,e);
	for(auto it: v)
		cout<<it<<" ";
	
	return 0;
}