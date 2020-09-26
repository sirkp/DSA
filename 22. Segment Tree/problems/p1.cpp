// https://practice.geeksforgeeks.org/problems/range-sum-queries2353/1/?track=DSASP-Segment-Tree&batchId=154
void updateUtil(ll* tree, int ss, int se, int si, int index, int diff){
    if(index<ss || index>se)
        return;
    tree[si] += diff;

    if(se>ss){
        int mid = (ss+se)/2;
        updateUtil(tree, ss, mid, (2*si)+1, index, diff);
        updateUtil(tree, mid+1, se, (2*si)+2, index, diff);
    }
}

void updateValue(int *arr, ll *tree, int n, int index, int new_val) {
    int diff = new_val - arr[index];
    arr[index] = new_val;
    updateUtil(tree, 0, n-1, 0, index, diff);
}


ll getSumUtil(ll *tree, int ss, int se, int si, int qs, int qe){
    if(qe<ss || qs>se)
        return 0;
    else if(ss>=qs && qe>=se)
        return tree[si];
    else{
        int mid = (ss+se)/2;
        return (getSumUtil(tree, ss, mid, (2*si)+1, qs, qe)+getSumUtil(tree, mid+1, se, (2*si)+2, qs, qe));
    }
}

ll getsum(ll *tree, int n, int l, int r) {
    return getSumUtil(tree, 0, n-1, 0, l, r);
}