// https://practice.geeksforgeeks.org/problems/connect-nodes-at-same-level/1/?track=DSASP-Tree&batchId=154
void connect(Node *p){
    queue<Node*> q;
    q.push(p);
    q.push(NULL);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if(temp==NULL){
            if(q.size()>0)
                q.push(NULL);
        }else{
            temp->nextRight = q.front();
            if(temp->left!=NULL)
                q.push(temp->left);
            if(temp->right!=NULL)
                q.push(temp->right);
        }
    }
}