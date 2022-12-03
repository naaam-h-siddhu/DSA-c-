#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
#define pb push_back
#define fr first
#define sc second
#define all(x) (x).begin(),(x).end()
int f(int n, vector<int> &dp) {
	// if (n<=1) return n;
	if(dp [n] != -1) return dp [n];
	return dp[n] = f(n-1, dp) + f(n-2, dp) ;
}
signed main(){
	ios_base::sync_with_stdio(false);  
	cin.tie(NULL); 
	
	int n;
	cin>>n;
	vector<int> dp(n+1,-1);
	dp[0]=0;dp[1]=1;//this is the DP array which store the value of all the f(i);
	cout<<f(n,dp);
	dbg(dp);

	//TC--> O(N)
	//SC--> O(N)
	return 0;
} /*      f(5)
		  /  \
		 /    \
	   f(4)   f(3)
	   /  \   /  \

*/