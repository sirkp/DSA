// https://practice.geeksforgeeks.org/problems/level-order-traversal/1/?track=PC-W6-T&batchId=154
vector<int> levelOrder(Node* node){
    vector<int> v;
    if(node!=NULL){
        queue<Node*> q;
        q.push(node);
        
        Node* temp;
        while(!q.empty()){
            temp = q.front();
            if(temp->left!=NULL)
                q.push(temp->left);
            if(temp->right!=NULL)
                q.push(temp->right);
            q.pop();
            v.push_back(temp->data);
        }
    }
    return v;
}
