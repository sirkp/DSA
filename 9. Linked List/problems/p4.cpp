// https://practice.geeksforgeeks.org/problems/insert-in-middle-of-linked-list/1/?track=PC-W5-LL&batchId=154
int getCount(struct Node* head){
    int c = 0;
    while(head!=NULL){
        c++;
        head = head->next;
    }
    return c;
}

Node* getPthNode(Node* head, int p){
    if(head==NULL)
        return NULL;
    int i = 0;
    while(head!=NULL && i<p){
        head = head->next;
        i++;
    }
    return head;
}

void insertAtPth(Node *head, int pos, int data){
    Node* node = new Node(data);
    Node* last = getPthNode(head, pos);
    if(last!=NULL){
        node->next = last->next;
        last->next = node;
    }
}

Node* insertInMiddle(Node* head, int x){
    int n = getCount(head);
    if(n%2==1){
        insertAtPth(head, n/2, x);
    }else{
        insertAtPth(head, (n/2-1), x);
    }
    return head;
}
