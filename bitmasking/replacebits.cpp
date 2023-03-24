#include<bits/stdc++.h>
using namespace std;
// you are given two 32-Bits number , N and M , and two bit position i and j. 
// Write a method to set all bits between i and j in n equal to M. 
// M (becomes a substring of N locationed at and starting at j)
// Exaple:
// N = 10000000000;
// M = 10101;16 8 4 2 1
// i = 2,j = 6
// Output :  1001010100
void clearBitInRange(int &n,int i,int j){
	int a=(~0)<<(j+1);
	int b=(1<<i)-1;
	int mask= a|b;
	n=n&mask;
}
void clearIBits( int &a, int i, int j){
    
    int n = ((~0)<<(j+1));
    int n2 = ((~0)>>i);
    n2 = ~(n2<<i);
    int x = n|n2;
    a = a&x;
}
int main(){
	int a = 15;
	int b = 2;
	int i = 1;
	int j = 3;
	clearBitInRange(a,i,j);
	b = b << i;
	a = a|b;
	cout<<a<<endl;
	

	
	
}