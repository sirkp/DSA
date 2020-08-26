// https://practice.geeksforgeeks.org/problems/reverse-a-linked-list/1/?track=PC-W5-LL&batchId=154
struct Node* reverseList(struct Node *head){
    Node *node = head, *prev = NULL, *nextNode = NULL;

    while(node!=NULL){
        nextNode = node->next;
        node->next = prev;
        prev = node;
        node = nextNode;
    }
    head = prev;
    return head;
}