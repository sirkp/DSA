// https://practice.geeksforgeeks.org/problems/level-order-traversal-line-by-line/1/?track=PC-W6-T&batchId=154
void levelOrder(Node* node){
    if(node!=NULL){
        queue<Node*> q;
        q.push(node);
        q.push(NULL);
        
        Node* temp;
        while(!q.empty()){
            temp = q.front();
            if(temp==NULL){
                cout<<"$ ";
                q.pop();
                if(!q.empty())
                    q.push(NULL);
            }else{
                if(temp->left!=NULL)
                    q.push(temp->left);
                if(temp->right!=NULL)
                    q.push(temp->right);
                q.pop();
                cout<<temp->data<<" ";
            }
        }
    }
}