// https://practice.geeksforgeeks.org/problems/count-nodes-of-linked-list/1/?track=PC-W5-LL&batchId=154
int getCount(struct Node* head){
    int c = 0;
    while(head!=NULL){
        c++;
        head = head->next;
    }
    return c;
}