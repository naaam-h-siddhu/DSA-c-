#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fr first
#define sc second
#define all(x) (x).begin(),(x).end()
class Node{
	public:
		Node *next;
		int data;
		int exp;
		Node(int data,int exp){
			this->data=data;
			this->exp = exp;
			this->next= NULL;
		}

};
void insertnode(Node* &head,int data,int exp){
	Node *temp =new Node(data,exp);
	temp->next= head;
	head = temp;
}
void print(Node* &head){
	Node*temp = head;
	while(temp!=NULL){

		cout<<temp->data<<"X^"<<temp->exp<<" ";
		temp= temp->next;
	}
	cout<<endl;
}
void add(Node* &first,Node* &second){
	Node *temp = NULL;

	while(first!=NULL && second!=NULL){
		int x,y;
		if(first->exp==second->exp){
			x= first->data+second->data;
			y= first->exp;
			first= first->next;
			second=second->next;

		}
		else if(first->exp>second->exp){
			x= first->data;
			y= first->exp;
			first= first->next;
		}
		else{
			x= second->data;
			y= second->exp;
			second = second->next;
		}
		if(temp==NULL) temp= new Node(x,y);
		else{
			insertnode(temp,x,y);
		}
	}
	while(first!=NULL){
		if(temp==NULL) temp= new Node(first->data,first->exp);
		else insertnode(temp,first->data,first->exp);
		first=first->next;
	}
	while(second){
		if(temp==NULL) temp= new Node(second->data,second->exp);
		else insertnode(temp,second->data,second->exp);
		second=second->next;
	}
	print(temp);
}

int main(){
	ios_base::sync_with_stdio(false);  
	cin.tie(NULL); 
	
	Node *head1 = new Node(6,3);
	insertnode(head1,6,0);
	
	Node *head2 = new Node(6,2);
	insertnode(head2,6,1);
	
	add(head1,head2); 
	return 0;
}