// segment tree
int getSumUtil(vector<int> tree, int si, int ss, int se, int qs, int qe){
    if(ss> qe || qs>se)
        return 0;
    else if(qs<=ss && qe>=se)
        return tree[si];
    else{
        int mid = (ss+se)/2;
        return (getSumUtil(tree, 2*si+1, ss, mid, qs, qe)+getSumUtil(tree, 2*si+2, mid+1, se, qs, qe));
    }
}

int getSum(vector<int> tree, int n, int qs, int qe){
    if(qs>qe)
        return 0;
    return getSumUtil(tree, 0, 0, n-1, qs, qe);
}


void updateUtil(vector<int> tree, int newNum, int i, int si, int ss, int se){
    if(i<ss || i>se)
        return;
    else if(ss==i){
        tree[si] = newNum;
    }else{
        int mid = (se+ss)/2;
        updateUtil(tree, newNum, i, 2*si+1, ss, mid);
        updateUtil(tree, newNum, i, 2*si+2, mid+1, se);
        tree[si] = tree[2*si+1] + tree[2*si+2];
    }
}

void update(vector<int> tree, int arr[], int n, int i, int newVal){
    updateUtil(tree, newVal, i, 0, 0, n-1);
}


int constructUtil(int arr[], vector<int>& tree, int ss, int se, int si){// O(n)
    if(ss==se){
        tree[si] = arr[ss];
    }else{
        int mid = (ss+se)/2;
        tree[si] = constructUtil(arr, tree, ss, mid, ((2*si)+1)) + constructUtil(arr, tree, mid+1, se, ((2*si)+2));
    }
    return tree[si];
}

vector<int> constructST(int arr[], int n){
    int x = (int)(ceil(log2(n)));
    int maxSize = (2*(int)pow(2,x))-1;// 4*n v chalega
    vector<int> tree(maxSize, -1);

    int temp = constructUtil(arr, tree, 0, (n-1), 0);
    return tree;
}

void segmentTree(int arr[], int n){
    vector<int> tree = constructST(arr, n);
    printVector(tree);
    testGetAns(tree, arr, n);
    testUpdate(tree, arr, n);
}

