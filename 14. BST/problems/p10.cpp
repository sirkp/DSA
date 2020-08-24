// https://practice.geeksforgeeks.org/problems/pair-sum-in-bst/1/
// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/submissions/
bool findPair(Node* node, int x) {
    if(node==NULL)
        return false;

    Node* node1 = node;
    Node* node2 = node;

    stack<Node*> s1, s2;

    while(node1 || node2 || ( (!s1.empty() && !s2.empty()) && (s1.top()->data<s2.top()->data) ) ){
        if(node1){
            s1.push(node1);
            node1 = node1->left;
        }else if(node2){
            s2.push(node2);
            node2 = node2->right;
        }else{
            if((s1.top()->data+s2.top()->data) == x)
                return true;
            else if((s1.top()->data+s2.top()->data) < x){
                node1 = s1.top()->right;
                s1.pop();
            }else{
                node2 = s2.top()->left;
                s2.pop();
            }
        }
    }
    return false;
}
