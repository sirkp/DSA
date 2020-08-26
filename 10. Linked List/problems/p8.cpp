// https://practice.geeksforgeeks.org/problems/remove-duplicates-from-an-unsorted-linked-list/1/?track=PC-W5-LL&batchId=154
void delNode(Node* prev){// prev is not last node
    Node* nextNode = prev->next;
    prev->next = prev->next->next;
    delete nextNode;
}

Node* removeDuplicates(Node *head){
    unordered_set<int> hash;
    Node* node = head;
    hash.insert(node->data);
    Node* prev = node;
    node = node->next;
    while(node!=NULL){
        if(hash.find(node->data)==hash.end()){
            hash.insert(node->data);
            prev = node;
            node = node->next;
        }else{
            node = node->next;
            delNode(prev);
        }
    }
    return head;
}
