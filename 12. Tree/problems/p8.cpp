// https://practice.geeksforgeeks.org/problems/level-order-traversal-in-spiral-form/1/?track=PC-W6-T&batchId=154
void printSpiral(Node* node){
    if(node!=NULL){
        queue<Node*> q;
        stack<int> s;
        q.push(node);
        q.push(NULL);
        
        bool rear = true;
        Node* temp;
        while(!q.empty()){
            temp = q.front();
            if(temp==NULL){
                while(rear && !s.empty()){
                    cout<<s.top()<<" ";
                    s.pop();
                }
                rear = !rear;
                q.pop();
                if(!q.empty())
                    q.push(NULL);
            }else{
                if(temp->left!=NULL)
                    q.push(temp->left);
                if(temp->right!=NULL)
                    q.push(temp->right);    
                q.pop();
                if(rear)
                    s.push(temp->data);
                else
                    cout<<temp->data<<" ";
            }
        }
    }
}
