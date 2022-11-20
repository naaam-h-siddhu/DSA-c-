#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fr first
#define sc second
#define all(x) (x).begin(),(x).end()
class Node{
public:
	Node* next;
	int data;
	Node(int data){
		this->data =data;
		this->next =NULL;
	}
	~Node(){
		int val = this->data;
		if(this->next!=NULL){
			delete next;
			next=NULL;
		}
		cout<<"Node delete that is "<<val<<endl;
	}
};
void insertNode(Node* &tail, int element, int d){
	if(tail==NULL){
		Node* newnode = new Node(d);
		tail= newnode;
		newnode ->next= newnode;
	}
	else{
		Node* curr = tail;
		while(curr->data !=element){
			curr=curr->next;

		}
		Node* temp= new Node(d);
		temp->next = curr->next;
		curr->next = temp;

	}

}
void print(Node* &tail){
	Node* temp = tail;
	if(tail == NULL) {
        cout << "List is Empty "<< endl;
        return ;
    }
	do{
		cout<<tail->data<<" ";
		tail= tail->next;
	}while(tail!=temp);
	cout<<endl;
}
void deletenode(Node* &tail,int d){
	if(tail==NULL){
		cout<<"list is empty "<<endl;
		return;
	}
	else{
		Node* prev = tail;
		Node* curr= prev->next;
		while(curr->data!=d){
			prev= curr;
			curr = curr->next;
		}
		prev->next= curr->next;
		//if only 1 element in LL
		if(curr==prev){
			tail= NULL;
		}
		
		if(tail==curr)
			tail=prev;
		curr->next=NULL;
		delete curr;
	}


}
int main(){
	ios_base::sync_with_stdio(false);  
	cin.tie(NULL); 
	Node* tail= NULL;
	insertNode(tail,5,12);
	// print(tail);
	// insertNode(tail,12,13);
	// print(tail);
	// insertNode(tail,13,14);
	// print(tail);
	// insertNode(tail,14, 15);
	print(tail);
	deletenode(tail, 12);
	print(tail);

	

	return 0;
}