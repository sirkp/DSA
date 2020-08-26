// https://practice.geeksforgeeks.org/problems/levelorder-traversal-of-a-bst/1/?track=DSASP-BST&batchId=154
vector<int> levelOrder(Node* node){
    vector<int> v;
    if(node!=NULL){
        queue<Node*> q;
        q.push(node);

        while(!q.empty()){
            Node* temp = q.front();
            q.pop();
            v.push_back(temp->data);

            if(temp->left!=NULL)
                q.push(temp->left);
            if(temp->right!=NULL)
                q.push(temp->right);
        }

    }
    return v;
}