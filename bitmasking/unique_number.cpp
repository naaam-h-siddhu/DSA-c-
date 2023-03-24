#include<bits/stdc++.h>
using namespace std;
int uniqueNo(vector<int> arr){
	int xorr = 0;
	for(auto it:arr){
		xorr = xorr^it;
	}
	return xorr;
}
int main(){
	vector<int> arr= {1,3,5,4,3,1,5};
	cout<<uniqueNo(arr)<<endl;
}