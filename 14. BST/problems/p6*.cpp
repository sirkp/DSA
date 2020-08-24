// https://practice.geeksforgeeks.org/problems/print-common-nodes-in-bst/1
vector <int> printCommon(Node *node1, Node *node2){
    vector<int> v;
    stack<Node*> s1;
    stack<Node*> s2;

    while(node1!=NULL || node2!=NULL || (!s1.empty() && !s2.empty())){
        if(node1){
            s1.push(node1);
            node1 = node1->left;
        }else if(node2){
            s2.push(node2);
            node2 = node2->left;
        }else{
            if(s1.top()->data<s2.top()->data){
                node1 = s1.top()->right;
                s1.pop();
            }else{
                if(s1.top()->data==s2.top()->data){
                    v.push_back(s1.top()->data);
                }
                node2 = s2.top()->right;
                s2.pop();
            }
        }
    }
    return v;
}