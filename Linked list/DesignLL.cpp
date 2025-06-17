class MyLinkedList {
public:
    class Node {
        public:
        int val;
        Node* next;
        Node(int val) {
            this->val = val;
            this->next = nullptr;
        }
    };
    Node* head;
    int n;
    MyLinkedList() {
        this->head = nullptr;
        n = 0;
    }

    int get(int index) {
        if (index >= n || index < 0) {
            return -1;
        }
        Node* temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        return temp->val;
    }

    void addAtHead(int val) {
        Node* temp = new Node(val);
        if (!head) {
            head = temp;
        } else {
            temp->next = head;
            head = temp;
        }
        n++;
    }

    void addAtTail(int val) {
        Node* temp = head;
        Node* nn = new Node(val);
        if (!head) {
            head = nn;
            n++;
        } else {
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = nn;
            n++;
        }
    }

    void addAtIndex(int index, int val) {
        if(index>n) return;
        if(index<=0){
            addAtHead(val);
            return;
        }
        if(index==n){
            addAtTail(val);
            return;
        }
        Node* temp=head;
        Node* nn=new Node(val);
        for(int i=0;i<index-1;i++){
            temp=temp->next;
        }
        nn->next=temp->next;
        temp->next=nn;
        n++;
    }

    void deleteAtIndex(int index) {
        if(index>=n ||index<0){
            return;
        }
        if(index==0){
            Node* del=head;
            head=head->next;
            n--;
            delete del;
        }
        else{
        Node*temp=head;
        for(int i=0;i<index-1;i++){
            temp=temp->next;
        }
        Node* del=temp->next;
        temp->next=temp->next->next;
        n--;
        delete del;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
