// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description/
pair<int, bool> util(Node* node, int x, int &ans){
    if(node!=NULL){
        pair<int, int> l = util(node->left, x, ans);
        pair<int, int> r = util(node->right, x, ans);
        

        if(node->data==x)
            return make_pair(1,true);
        else{
            if(l.second||r.second)
                ans = max(ans, (l.first+r.first));
            
            if(l.second)
                return make_pair(l.first+1, true);
            else if(r.second)
                return make_pair(r.first+1, true);
            else
                return make_pair(max(l.first, r.first)+1, false);
        }
    }else
        return make_pair(0, false);
}

int minTime(Node* root, int target) {
    int ans = 0;
    pair<int, bool> p = util(root, target, ans);
    return ans;
}
