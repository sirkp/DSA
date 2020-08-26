// https://practice.geeksforgeeks.org/problems/identical-linked-lists/1/?track=PC-W5-LL&batchId=154
bool areIdentical(struct Node *head1, struct Node *head2){
    while(head1!=NULL && head2!=NULL){
        if(head1->data!=head2->data)
            return false;

        head1 = head1->next;
        head2 = head2->next;
    }
    if(head1==NULL && head2==NULL)
        return true;
    else
        return false;    
}
sbi.10367@sbi.co.in