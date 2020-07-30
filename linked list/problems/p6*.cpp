// https://practice.geeksforgeeks.org/problems/delete-without-head-pointer/1/?track=PC-W5-LL&batchId=154
void deleteNode(Node *node){
    Node* nextNode = node->next;
    node->data = nextNode->data;
    node->next = nextNode->next;
    delete nextNode;
}