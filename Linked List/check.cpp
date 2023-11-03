


Node* reverse(Node*& head){
    if(head == nullptr){
        return nullptr;
    }

    Node* prev = head;
    Node* front = head->next;

    if(prev->next){
        prev->next = reverse(prev->next);
        return front;
    }
}