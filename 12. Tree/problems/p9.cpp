// https://practice.geeksforgeeks.org/problems/maximum-width-of-tree/1/?track=PC-W6-T&batchId=154
int getMaxWidth(Node* node){
    if(node!=NULL){
        queue<Node*> q;
        q.push(node);
        q.push(NULL);
        
        Node* temp;
        int maxWeidth = 1;// first node is pushed
        while(!q.empty()){
            temp = q.front();
            if(temp==NULL){
                q.pop();
                maxWeidth = max(maxWeidth, (int)q.size());
                if(!q.empty())
                    q.push(NULL);
            }else{
                if(temp->left!=NULL)
                    q.push(temp->left);
                if(temp->right!=NULL)
                    q.push(temp->right);
                q.pop();
            }
        }
        return maxWeidth;
    }else
        return -1;
}
