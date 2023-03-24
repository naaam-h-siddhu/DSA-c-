#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fr first
#define sc second
#define srt(a) sort((a).begin(),(a).end());
#define dsrt(a) sort((a).begin(),(a).end(),greater<>())
string arr []= {"zero", "one", "two" , "three", "four", "five", "six", "seven", "eight", "nine"};
void num_spell(int n){
	if(n==0)
		return;
	int last_digit = n%10;
	num_spell(n/10);
	cout<<arr[last_digit]<<" ";

}
int main(){
	int n;
	cin>>n;
	num_spell(n);
	
	return 0;
}