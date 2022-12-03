#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fr first
#define sc second
#define all(x) (x).begin(),(x).end()
class Node{
public:
	Node* prev;
	Node* next;
	int data;
	Node(int data){
		this ->data= data;
		this -> prev = NULL;
		this -> next = NULL;

	}
};
void insertNode(Node* &tail, int d){
	if(tail == NULL)
	{
		Node *newnode = new Node(d);
		tail = newnode;
		tail ->next = tail;
		tail -> prev = tail;

	}
	
}
int main(){
	ios_base::sync_with_stdio(false);  
	cin.tie(NULL); 
	

	return 0;
}