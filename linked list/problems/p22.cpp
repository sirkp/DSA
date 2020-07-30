// https://practice.geeksforgeeks.org/problems/merge-sort-on-doubly-linked-list/1/?track=PC-W5-LL&batchId=154
Node* merge(Node* head1, Node* head2){
    Node* head = NULL;
    if(head1==NULL)
        return head2;
    else if(head2==NULL)
        return head1;
    else{
        if(head1->data<head2->data){
            head = head1;
            head->next = merge(head1->next, head2);
        }else{
            head = head2;
            head->next = merge(head1, head2->next);
        }
        return head;
    }
}

void splitList(Node* head, Node** head1, Node** head2){
    if(head==NULL||head->next==NULL){
        (*head1) = head;
        (*head2) = NULL;
    }else{
        Node *slow = head, *fast = head->next;
        while(fast!=NULL){
            fast = fast->next;
            if(fast!=NULL){
                fast = fast->next;
                slow = slow->next;
            }
        }
        (*head1) = head;
        (*head2) = slow->next;
        slow->next = NULL;
    }
}

Node* mergeSort(Node* head){
    if(head==NULL|| head->next==NULL)
        return head;

    Node *head1, *head2;
    splitList(head, &head1, &head2);
    head1 = mergeSort(head1);
    head2 = mergeSort(head2);
    return merge(head1, head2);
}

Node* setPrev(Node* head){
    Node *node = head, *prevNode = NULL;
    while(node!=NULL){
        node->prev = prevNode;
        prevNode = node;
        node = node->next;
    }
    return head;
}

struct Node *sortDoubly(struct Node *head){
    head = mergeSort(head);
    head = setPrev(head);
    return head;
}
