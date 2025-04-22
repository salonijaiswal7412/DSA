/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */

Node* merge(Node* l1,Node* l2){
	Node* dummy=new Node(-1);
	Node* res=dummy;
	while(l1 && l2){
		if(l1->data<l2->data){
			res->child=l1;
			res=l1;
			l1=l1->child;
		}
		else{
			res->child=l2;
			res=l2;
			l2=l2->child;
		}
		res->next=nullptr;
	}
	if(l1) res->child=l1;
	else res->child=l2;
	if(dummy->child) dummy->child->next=nullptr;
	return dummy->child;
}
Node* flattenLinkedList(Node* head) 
{
	// Write your code here
	if(!head ||!head->next){
		return head;
	}
	Node* merged=flattenLinkedList(head->next);
	return head=merge(head,merged);
}
