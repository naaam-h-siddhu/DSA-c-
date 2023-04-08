#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fr first
#define sc second
#define srt(a) sort((a).begin(),(a).end());
#define dsrt(a) sort((a).begin(),(a).end(),greater<>())
int todigit(char c){
	return c-'0';
}
char tochar(int n){
	return n +'0';
}
string addNumber(string n1, string n2){
	if(n1.length()>n2.length())
		swap(n1,n2);
	string ans= "";
	reverse(n1.begin(), n1.end());
	reverse(n2.begin(), n2.end());
	int carry = 0;
	for (int i = 0; i < n1.length(); ++i)
	{
		int a = todigit(n1[i]);
		int b = todigit(n2[i]);
		int sum = a+b+carry;
		ans.pb(tochar(sum%10));
		carry = sum/10;


	}
	for(int i = n1.length();i<n2.length();++i){
		int a = todigit(n2[i]);
		int sum = a+carry;
		ans.pb(tochar(sum%10));
		carry = sum/10;
	}
	return ans;
}
int main(){
	string s1,s2;
	cin>>s1>>s2;
	cout<<addNumber(s1,s2);
	return 0;
}