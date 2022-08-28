#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mod 1000000007
#define endl '\n'
bool isPalindrome(string s){
    int x;
    x=s.length();
    for(int i=0;i<x;i++){
        if(s[i]!=s[x-i-1])
            return false;
    }
    return true;
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	string str;
	cin>>str;
	if(isPalindrome(str))
		cout<<"its a palli"<<endl;
	else
		cout<<"its not palli "<<endl;
	return 0;
}
