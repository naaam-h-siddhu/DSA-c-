#include<bits/stdc++.h>
using namespace std;
int uniqueNo2(vector<int> arr){
	int n= arr.size();
	int result = 0;
	for (int i = 0; i < n; ++i)
	{
		result = result ^arr[i];
	}
	 
}