// https://practice.geeksforgeeks.org/problems/make-binary-tree/1/?track=DSASP-Tree&batchId=154
void convert(Node *head, TreeNode *&root) {
    root = new TreeNode(head->data);
    head = head->next;
    
    queue<TreeNode*> q;
    q.push(root);
    
    while(head!=NULL){
        TreeNode* temp = q.front();
        q.pop();
        
        temp->left = new TreeNode(head->data);
        q.push(temp->left);
        head = head->next;
        
        if(head!=NULL){
            temp->right = new TreeNode(head->data);
            q.push(temp->right);
            head = head->next;
        }
    }
    
}