//XOR of two unique number > 0
//A bit is set when it is present in exactly one of the two number
#include<bits/stdc++.h>
using namespace std;
int uniqueNo2(vector<int> arr){
	int n= arr.size();
	int result = 0;
	for (int i = 0; i < n; ++i)
	{
		result = result ^arr[i];
	}
	//after doing this loop we will get the xor of the 2 unique number

	//positoin of the set bit
	int pos = 0;
	int temp= result;
	while((temp&1) == 0){
		pos++;
		temp = temp>>1;
	}
	// filter out the number from the arroy which have set bit as 'pos'
	int setA = 0;
	int setB = 0;
	int mask = (1<<pos);
	for(int i  =0;i<arr.size();i++)
	{
		if((arr[i] & mask)> 0){
			setA ^= arr[i];
		}
		else
			setB ^=arr[i];
	}	 
	cout<<setA<<endl;
	cout<<setB<<endl;
}
int main(){
	vector<int> arr  = {1,3,5,3,1,5,7,4};
	uniqueNo2(arr);
}