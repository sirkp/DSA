// https://practice.geeksforgeeks.org/problems/convert-level-order-traversal-to-bst/1/?track=DSASP-BST&batchId=154
Node* constructBst(int arr[], int n){
    queue<pair<Node*, pair<int, int>>> q;
    int i = 0;
    Node* root = new Node(arr[i]);
    q.push(make_pair(root, make_pair(INT_MIN, INT_MAX)));
    i++;

    while(!q.empty() && i<n){
        Node* node = q.front().first;
        int low = q.front().second.first;
        int high = q.front().second.second;
        q.pop();

        if(arr[i]>low && arr[i]<node->data){
            node->left = new Node(arr[i]);
            q.push(make_pair(node->left, make_pair(low, node->data)));
            i++;
        }

        if(arr[i]>node->data && arr[i]<high){
            node->right = new Node(arr[i]);
            q.push(make_pair(node->right, make_pair(node->data, high)));
            i++;
        }
    }
	return root;
}
