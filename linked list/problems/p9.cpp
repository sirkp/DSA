// https://practice.geeksforgeeks.org/problems/merge-two-sorted-linked-lists/1/?track=PC-W5-LL&batchId=154
Node* sortedMerge(Node* head1, Node* head2){
    Node* head = NULL;
    if(head1==NULL)
        return head2;
    else if(head2==NULL)
        return head1;
    else{
        if(head1->data<head2->data){
            head = head1;
            head->next = sortedMerge(head1->next, head2);
        }else{
            head = head2;
            head->next = sortedMerge(head1, head2->next);
        }
        return head;
    }
}