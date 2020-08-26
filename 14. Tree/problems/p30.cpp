// https://practice.geeksforgeeks.org/problems/serialize-and-deserialize-a-binary-tree/1/?track=DSASP-Tree&batchId=154
int height(Node* node){
    if(node!=NULL){
        return (max(height(node->left), height(node->right))+1);
    }else
        return 0;
}

void serialize(Node *root, vector<int> &v){
    if(root!=NULL){
        int h = height(root);
        queue<Node*> q;
        q.push(root);
        q.push(NULL);

        int l = 1;
        while(!q.empty()){
            Node* node = q.front();
            q.pop();
            if(node==NULL){
                l++;
                if(!q.empty())
                    q.push(NULL);
            }else{
                v.push_back(node->data);
                
                if(node->left!=NULL)
                    q.push(node->left);
                else if(l!=h && node->data!=-1)
                    q.push(new Node(-1));

                if(node->right!=NULL)
                    q.push(node->right);
                else if(l!=h && node->data!=-1)
                    q.push(new Node(-1));
            }
        }
    }
}

Node * deSerialize(vector<int> &v){
    int i = 0;
    Node* root = new Node(v[i++]);
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty() && i<(int)v.size()){
        Node* node = q.front();
        q.pop();

        if(v[i]!=-1){
            node->left = new Node(v[i]);
            q.push(node->left);
        }
        i++;

        if(i<(int)v.size() && v[i]!=-1){
            node->right = new Node(v[i]);
            q.push(node->right);
        }
        i++;
    }
    
    return root;
}
