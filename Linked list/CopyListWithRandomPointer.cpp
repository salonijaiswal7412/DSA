//using hashmaps
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp=head;
        unordered_map<Node*,Node*> m;
        while(temp){
            Node* newnode=new Node(temp->val);
            m[temp]=newnode;
            temp=temp->next;
            
        } 
        temp=head;
        while(temp){
            Node* CopyNode=m[temp];
            CopyNode->next=m[temp->next];
            CopyNode->random=m[temp->random];
            temp=temp->next;
        }
        return m[head];
        
        
    }
};
//space optimized
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp=head;
        while(temp){
            Node* copy=new Node(temp->val);
            copy->next=temp->next;
            temp->next=copy;
            temp=temp->next->next;
        }
        temp=head;
        while(temp){
            Node* copy=temp->next;
            if(temp->random){
                copy->random=temp->random->next;
            }
            temp=copy->next;
        }
        temp=head;
        Node* dummy=new Node(-1);
        Node* res=dummy;
        while(temp){
            res->next=temp->next;
            temp->next=temp->next->next;

            temp=temp->next;
            res=res->next;
        }
        return dummy->next;
        
    }
};
