// https://practice.geeksforgeeks.org/problems/range-min-max-queries4557/1/?track=DSASP-Segment-Tree&batchId=154
PII getMinMaxUtil(PII* tree, int ss, int se, int si, int qs, int qe){
    if(qe<ss || qs>se)
        return {INT_MAX, INT_MIN};
    else if(qs<=ss && qe>=se)
        return tree[si];
    else{
        int mid = (ss+se)/2;
        PII left = getMinMaxUtil(tree, ss, mid, (2*si)+1, qs, qe);
        PII right = getMinMaxUtil(tree, mid+1, se, (2*si)+2, qs, qe);
        return {min(left.first, right.first), max(left.second, right.second)};
    }
}

PII getMinMax(PII *tree, int *arr, int n, int qs, int qe){
    return getMinMaxUtil(tree, 0, n-1, 0, qs, qe);
}

void updateValueUtil(PII* tree, int ss, int se, int si, int i, int new_val){
    if(i<ss || i>se)
        return;

    if(se==ss)
        tree[si] = {new_val, new_val};
        
    if(se>ss){
        int mid = (ss+se)/2;
        updateValueUtil(tree, ss, mid, (2*si)+1, i, new_val);
        updateValueUtil(tree, mid+1, se, (2*si)+2, i, new_val);
        tree[si] = {min(tree[(2*si)+1].first, tree[(2*si)+2].first), max(tree[(2*si)+1].second, tree[(2*si)+2].second)};
    }
}

void updateValue(int *arr, PII *tree, int n, int index, int new_val){
    arr[index] = new_val;
    updateValueUtil(tree, 0, n-1, 0, index, new_val);
}