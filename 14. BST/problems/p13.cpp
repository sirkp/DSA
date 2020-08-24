// https://practice.geeksforgeeks.org/problems/implementing-ceil-in-bst/1/
int ceil(Node* node, int key){
    if(node){
        // if(key==node->data)
        //     return node->data;
        if(key>node->data)
            return ceil(node->right, key);
        else{
            int l = ceil(node->left, key);
            return min(l, node->data);
        }
    }else
        return INT_MAX;
}

int findCeil(Node* node, int x) { 
    int ans = ceil(node, x);
    if(ans==INT_MAX)
        return -1;
    else
        return ans; 
} 
