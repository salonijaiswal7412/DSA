
int searchInLinkedList(Node<int> *head, int k) {
    // Write your code here.
    Node<int> *nn=head;
    while(nn!=NULL){
        if(nn->data==k){
            return 1;
        }
        nn=nn->next;
    }
    return 0;
}
