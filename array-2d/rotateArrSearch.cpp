#include<bits/stdc++.h>
using namespace std;
int bs(vector<int> arr,int key){
	int n = arr.size();
	int s= 0;
	int e= n-1;
	while(s<=e){
		int mid = (s+e)/2;
		if(arr[mid]==key)
			return mid;
		//there will be 2 cases 
		//case 1 
		if(arr[s]<=arr[mid]){
			//left
			if(key>=arr[s] and key<= arr[mid]){
				e=mid-1;

			}
			else
				s=mid+1;
		}
		//case 2
		else{
			//right
			if(key<=arr[e] and key<=arr[mid])
				s= mid +1;
			else
				e=mid-1;

		}
	}
	return -1;
}
int main(){
	vector<int> arr{4,5,6,7,0,1,2,3};
	int key;
	cin>>key;
	cout<<bs(arr,key)<<endl;
}