// https://practice.geeksforgeeks.org/problems/preorder-to-postorder4423/1/
Node* constructTree(int arr[], int n) {
    stack<pair<Node*, pair<int, int>>> s;
    int i = 0;
    Node* root = newNode(arr[i]);
    s.push(make_pair(root, make_pair(INT_MIN, INT_MAX)));
    i++;
    while(!s.empty() && i<n){
        Node* node = s.top().first;
        int low = s.top().second.first;
        int high = s.top().second.second;
        if(arr[i]>low && arr[i]<node->data){
            node->left = newNode(arr[i]);
            s.push(make_pair(node->left, make_pair(low, node->data)));
            i++;
        }else if(arr[i]>node->data && arr[i]<high){
            node->right = newNode(arr[i]);
            s.push(make_pair(node->right, make_pair(node->data, high)));
            i++;
        }else{
            s.pop();
        }
    }
    return root;
}
