#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fr first
#define sc second
#define srt(a) sort((a).begin(),(a).end());
#define dsrt(a) sort((a).begin(),(a).end(),greater<>())

int power_func(int a, int b)
{
	if(b==0)
		return 1;
	return a*(power_func(a,b-1));

}
//opetimized power function
int fast(int a,int b){
	if(b==0)
		return 1;
	int subprblm = fast(a,b/2);
	int subprblmsq= subprblm*subprblm;
	if(b&1)
		return a*subprblmsq;
	return subprblmsq;
}
int main(){
	int a ,b;
	cin>>a>>b;
	cout<<fast(a,b);
	return 0;
}