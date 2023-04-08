#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fr first
#define sc second
#define srt(a) sort((a).begin(),(a).end());
#define dsrt(a) sort((a).begin(),(a).end(),greater<>())
void Printer(char arr[], int num){

	int j =0;
	while(num>0){
		int last_bit = num&1;
		if(last_bit){
			cout<<arr[j];
		}
		j++;
		num>>=1;
	}
	cout<<endl;

}
void subseter(char arr[],int n)
{
	for (int i = 0; i < (1<<n); ++i)
	{
		/* code */
		Printer(arr,i);
	}
}
int main(){
	
	char arr[1000];
	int n;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
	subseter(arr, n);

	    

	return 0;
}