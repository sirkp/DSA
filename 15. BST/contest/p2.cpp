// https://practice.geeksforgeeks.org/contest-problem/level-them-all4247543704281248/1/
void util(Node* node, int l, int level, int &ans){
    if(node){
        if(l==level)
            ans++;
        util(node->left, l+1, level, ans);
        util(node->right, l+1, level, ans);
    }
}

int Count(Node *node,int level){
    int ans = 0, l = 1;
    util(node, l, level, ans);
    return ans;
}