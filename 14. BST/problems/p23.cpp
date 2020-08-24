// https://practice.geeksforgeeks.org/problems/merge-two-bst-s/1/
vector<int> merge(Node *root1, Node *root2){
    stack<Node*> s1, s2;

    Node* node1 = root1;
    Node* node2 = root2;

    vector<int> v;
    while(node1 || node2 || !s1.empty() || !s2.empty()){
        if(node1){
            s1.push(node1);
            node1 = node1->left;
        }else if(node2){
            s2.push(node2);
            node2 = node2->left;
        }else{
            if(s2.empty() ||  (!s1.empty() && s1.top()->data<s2.top()->data)){
                v.push_back(s1.top()->data);
                node1 = s1.top()->right;
                s1.pop();
            }else{
                v.push_back(s2.top()->data);
                node2 = s2.top()->right;
                s2.pop();
            }
        }
    }
    return v;
}
