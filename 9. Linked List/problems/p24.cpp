// https://practice.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1/?track=PC-W5-LL&batchId=154
int getCount(struct Node* head){
    int c = 0;
    while(head!=NULL){
        c++;
        head = head->next;
    }
    return c;
}

Node* getIntersectionNode(Node* big, Node* small, int diff){
    int i = 0;
    while(i<diff){
        big = big->next;
        i++;
    }

    while(small!=big && small!=NULL && big!=NULL){
        small = small->next;
        big = big->next;
    }

    if(small==big && small!=NULL){
        return small;
    }else
        return NULL;
}

int intersectPoint(Node* head1, Node* head2){
    Node *big, *small;
    int len1 = getCount(head1), len2 = getCount(head2);
    if(len1>len2){
        big = head1;
        small = head2;
    }else{
        big = head2;
        small = head1;
    }
    Node* intrsecn = getIntersectionNode(big, small, abs(len1-len2));
    if(intrsecn!=NULL){
        return -1;
    }else
        return intrsecn->data;  
}
