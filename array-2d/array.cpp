#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fr first
#define sc second
#define srt(a) sort((a).begin(),(a).end());
#define dsrt(a) sort((a).begin(),(a).end(),greater<>())
int solve(int a, int b ){
		if((b-a)<(a-b) and (6-b)<(b-a)){
			b= (b+3+b);
			a = a+3;
			return solve(b,b)+b;
		}

	// a = a+1;
	return a+1;
}

int main(){
	int a =9,b =8,c =9;
	
	// cout<<a+b+c;
	cout<<solve(a,b);

	return 0;
}