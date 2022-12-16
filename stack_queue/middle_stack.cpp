#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fr first
#define sc second
#define all(x) (x).begin(),(x).end()
void deleteMiddle(stack<int>&inputStack, int N){
	stack<int> temp;
    int count=0;
    
    while(count<N/2){
        temp.push(inputStack.top());
       inputStack.pop();
        count++;
    }
    inputStack.pop();
    while(!temp.empty()){
        inputStack.push(temp.top());
        temp.pop();
        
    }
    
           
   
  
}
int main(){
	// ios_base::sync_with_stdio(false);  
	// cin.tie(NULL); 
	stack<int> st;
	st.push(1);
	st.push(3);
	st.push(5);
	st.push(7);
	deleteMiddle(st,3);
	while(!st.empty()){
		cout<<st.top()<<" ";
		st.pop();
	}	
	cout<<endl;


	return 0;
}
