// https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1/?track=PC-W5-LL&batchId=154
int getCount(Node* head){
    int c = 0;
    while(head!=NULL){
        c++;
        head = head->next;
    }
    return c;
}

Node* reverseList(struct Node *head){
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

struct Node* addTwoLists(struct Node* first, struct Node* second){
    Node *head1, *head2;
    if(getCount(first)>getCount(second)){
        head1 = first;
        head2 = second;
    }else{
        head1 = second;
        head2 = first;
    }
    head1 = reverseList(head1);
    head2 = reverseList(head2);

    Node *node1 = head1, *node2 = head2, *prev = NULL;

    int carry = 0, sum;
    while(node1!=NULL || carry>0){
        sum = carry;
        if(node2!=NULL){
            sum += node2->data;
            node2 = node2->next;
        }
        if(node1==NULL){
            node1 = new Node(sum%10);
            prev->next = node1;
        }else{
            sum += node1->data;
            node1->data = sum%10;
        }
        
        carry = sum/10;
        prev = node1;
        node1 = node1->next;   
    }
    return reverseList(head1);
    
}
