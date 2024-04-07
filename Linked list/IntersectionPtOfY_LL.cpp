Node* findIntersection(Node *firstHead, Node *secondHead)
{
    //Write your code here
    if(firstHead==nullptr||secondHead==nullptr)return nullptr;
    Node *t1=firstHead;
    Node *t2=secondHead;
    while(t1!=t2){
        t1=t1->next;
        t2=t2->next;
        if(t1==t2)
        return t1;
         if(t1==nullptr)t1=secondHead;
        if(t2==nullptr)t2=firstHead;
    }
    return t1;
}
