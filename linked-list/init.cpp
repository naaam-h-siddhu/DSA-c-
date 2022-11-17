#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fr first
#define sc second
#define all(x) (x).begin(),(x).end()
class Node{
public:
	int data;
	Node *next;

	Node(int data){
		this-> data = data;
		this-> next = NULL;

	}
};
int main(){
	ios_base::sync_with_stdio(false);  
	cin.tie(NULL); 
	
	Node* n1 = new Node(32);
	cout<< n1->data <<endl;
	cout<< n1->next <<endl;



	return 0;
}