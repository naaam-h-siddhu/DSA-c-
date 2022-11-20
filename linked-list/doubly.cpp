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
	Node* prev;
	int data;
	Node(int data){
		this->data=data;
		this->next=NULL;
		this->prev=NULL;
	}
	~Node(){
		if(next!=NULL)
		{
			delete next;
			next=NULL;
		}			
		cout<<"memory deleted"<<endl;

	}
};
//to print all the nodes in the DLL
void print(Node* &head)
{
	Node* temp= head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp= temp->next;
	}
	cout<<endl;
}
//to get the length of the DLL
int getLength(Node* &head){
	Node* temp= head;
	int len=0;
	while(temp!=NULL){
		len++;
		temp=temp->next;
	}
	return len;
}
void insertathead(Node* &head, int d){
	Node* temp= new Node(d);
	temp->next=head;
	head->prev=temp;
	head=temp;
}
void insertattail(Node* &tail,int d){
	Node* temp= new Node(d);
	temp->next=NULL;
	tail->next=temp;
	temp->prev=tail;
	tail=temp;
}
void insetatmid(Node* &head,Node* &tail,int pos,int d){
	if(pos==1){
		insertathead(head,d);
		return;
	}


	Node *temp= head;
	
	int count=1;
	while(count< pos-1){
		head=head->next;
		count++;
	}
	if(temp->next==NULL){
		insertattail(tail,d);
		return;
	}
	

}
void deletenode(Node* head, Node *tail, int position){//checking for head deletion
    if(position==1)
    {
        Node* temp=head;
        temp->next->prev=NULL;
        head=temp->next;
        temp->next=NULL;
        delete temp;    
    }
    else    // tail and middle case
    {
        Node* curr=head;
        Node* prev = NULL;

        int cnt=1;

        while(cnt<position)
        {
            prev=curr;
            curr=curr->next;
            cnt++;
        }
        //for tail deletion (to adjust the tail)
        if(curr->next==NULL)
        {
            tail=prev;
            prev->next=curr->next;  // null
            curr->prev=NULL;
            delete curr;
            return ;
        }
        // below case only execute when positoin is not head or tail
        // here only 1 step is neglected in the tail block
        curr->next->prev=curr->prev;
        prev->next=curr->next;
        curr->next=NULL;
        curr->prev=NULL;

        delete curr;
    }

}

int main(){
	ios_base::sync_with_stdio(false);  
	cin.tie(NULL); 
	Node* n1 = new Node(10);
	Node* head= n1;
	Node* tail= n1;
	print(head);
	// cout<<getLength(head)<<endl;
	insertathead(head,13);
	print(head);
	insertathead(head,18);
	print(head);

	insertattail(tail,113);
	print(head);
	insetatmid(head,tail,2,99);
	print(head);
	deletenode(head,tail,3);
	print(head);

	return 0;
}