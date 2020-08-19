// https://practice.geeksforgeeks.org/problems/check-if-subtree/1/?track=DSASP-Tree&batchId=154
void getInorder(Node* node, vector<int>& inorder){
    if(node!=NULL){
        getInorder(node->left, inorder);
        inorder.push_back(node->data);
        getInorder(node->right, inorder);
    }else
        inorder.push_back(-1);
}

void getPreorder(Node* node, vector<int>& preorder){
    if(node!=NULL){
        preorder.push_back(node->data);
        getPreorder(node->left, preorder);
        getPreorder(node->right, preorder);
    }else
        preorder.push_back(-1);
}

void computeLPSArray(vector<int> s, int m, int lps[]){ 
    lps[0] = 0;
    int len = 0;
    int i = 1;
    while(i<m){
        if(s[i]==s[len]){
            len++;
            lps[i] = len;
            i++;
        }else if(len==0){
            lps[i] = 0;
            i++;
        }else
            len = lps[len-1];
    }
} 

bool KMPSearch(vector<int> s, vector<int> p) {
    int n = s.size();
    int m = p.size();
    int lps[m];
    computeLPSArray(p, m, lps);

    int i = 0, j = 0;
    while(i<n){
        if(s[i]==p[j]){
            i++;
            j++;

            if(j==m)
                return true;
        }else{
            if(j==0)
                i++;
            else
                j = lps[j-1];    
        }
    }
    return false;
}



bool isSubTree(Node* T, Node* S) {
    
    vector<int> iS, pS, iT, pT;
    
    getPreorder(S, pS);
    getInorder(S, iS);
    
    getPreorder(T, pT);
    getInorder(T, iT);
    
    bool c1 = KMPSearch(iT, iS);
    bool c2 = KMPSearch(pT, pS);
    
    if(KMPSearch(iT, iS) && KMPSearch(pT, pS))
        return true;
    else
        return false;
}