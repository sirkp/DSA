// https://practice.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1/?track=PC-W5-LL&batchId=154
Node* getSmallest(Node* arr[], int k){
    Node* smallest = NULL;
    int pos = -1;

    for(int i=0;i<k;i++){
        if(arr[i]!=NULL){
            if(smallest==NULL || arr[i]->data<smallest->data){
                smallest = arr[i];
                pos = i;
            }
        }
    }
    if(smallest!=NULL)
        arr[pos] = arr[pos]->next;
    return smallest;
}

Node* mergeKLists(Node *arr[], int k){
    Node* nextNode = getSmallest(arr, k);
    Node *prev = NULL, *head = NULL;
    while(nextNode!=NULL){
        if(prev==NULL){
            head = nextNode;
        }else{
            prev->next = nextNode;
        }
        prev = nextNode;
        nextNode = getSmallest(arr, k);
    }
    if(prev!=NULL)
        prev->next = NULL;
    
    return head;


}
