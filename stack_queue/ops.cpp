#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fr first
#define sc second
#define all(x) (x).begin(),(x).end()
class Stack{
public:
	int *arr;
	int size;
	int top;
	Stack(int size){
		this->size = size;
		arr = new int[size];
		top = -1;
	}
	void push(int ele){
		if(size-top>1){
			top++;
			arr[top]=ele;

		}
		else
			cout<<"stack overflow "<<endl;
	}
	void pop(){
		if(top>=0){
			top--;
		}
		else
			cout<<"stack underflow"<<endl;
	}
	int peek(){
		if(top>=0)
			return arr[top];
		else
			cout<<"stack is empty "<<endl;
		return -1;
	}

	bool isempty(){
		if(top<=0)
			return true;
		else
			return false;
	}
 
};
int main(){
	ios_base::sync_with_stdio(false);  
	cin.tie(NULL); 
	Stack st(5);
	st.push(123);

	st.push(1234);
	st.push(7647);
	st.pop();
	cout<<st.peek()<<endl;


	return 0;
}