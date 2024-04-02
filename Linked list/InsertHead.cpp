Node* insertAtFirst(Node* list, int newValue) {
    // Write your code here
    Node * n=new Node(newValue);
    
    n->next=list;
    
    return n;
    
}
