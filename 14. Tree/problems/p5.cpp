// https://practice.geeksforgeeks.org/problems/determine-if-two-trees-are-identical/1/?track=PC-W6-T&batchId=154
bool isIdentical(Node *r1, Node *r2){
    if((r1!=NULL && r2!=NULL) && (r1->data==r2->data)){
        return (isIdentical(r1->left, r2->left) && isIdentical(r1->right, r2->right));
    }else if(r1==NULL&& r2==NULL)
        return true;
    else
        return false;
}