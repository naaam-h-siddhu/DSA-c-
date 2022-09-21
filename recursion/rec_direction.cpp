#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mod 1000000007
#define endl '\n'
void dec(int n){
  if(n==0)
    return ;
  cout<<n<<" ";
  dec(n-1);

}
void inc(int n){
  if(n==0)
    return ;
  dec(n-1);
  cout<<n<<" ";

}

int main(){
  cin.tie(0)->sync_with_stdio(0);
  int n;
  cin>>n;
  dec(n);
  cout<<endl;
  inc(n); 
  return 0;
}

