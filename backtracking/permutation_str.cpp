#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fr first
#define sc second
#define srt(a) sort((a).begin(),(a).end());
#define dsrt(a) sort((a).begin(),(a).end(),greater<>())
void permut(string s, int l , int r ){
	if(l==r){
		cout<<s<<endl;
		return;
	}
	for (int i = l; i <=r; ++i)
	{
		/* code */
		swap(s[l],s[i]);
		permut(s,l+1,r);
		swap(s[l],s[i]);
	}
}


int main(){
	string s;
	cin>>s;
	permut(s,0,s.size()-1);

	return 0;
}
//recursion tree of the above 
/*
                              permute(s, 0, n-1)
                      /                  |                  \
            permute(s, 1, n-1)     permute(s, 1, n-1)      permute(s, 1, n-1)
          /       |       \          /       |       \          /       |       \
permute(s, 2, n-1) ...... permute(s, 2, n-1) ......     permute(s, 2, n-1) ......
*/