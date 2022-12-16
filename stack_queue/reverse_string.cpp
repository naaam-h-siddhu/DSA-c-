#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fr first
#define sc second
#define all(x) (x).begin(),(x).end()

int main(){
	ios_base::sync_with_stdio(false);  
	cin.tie(NULL); 
	string s;
	cin>>s;
	stack<char > st;
	for (int i = 0; i < s.size(); ++i)
	{
		st.push(s[i]);
	}
	for (int i = 0; i < s.size(); ++i)
	{
		cout<<st.top();
		st.pop();
	}



	return 0;
}