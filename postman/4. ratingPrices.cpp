// rating prices
void constructSTUtil(vector<int>& tree, vector<int> ratings, int ss, int se, int si){
    if(ss==se)
        tree[si] = ratings[ss];
    else{
        int mid = (ss+se)/2;
        constructSTUtil(tree, ratings, ss, mid, (2*si)+1);
        constructSTUtil(tree, ratings, mid+1, se, (2*si)+2);
        tree[si] = max(tree[(2*si)+1], tree[(2*si)+2]);
    }
}

vector<int> constructST(vector<int> ratings){
    int n = (int)ratings.size();
    int x = (int)(ceil(log2(n)));
    int max_size = (2*(int)pow(2, x)) - 1;
    vector<int> tree(max_size);
    constructSTUtil(tree, ratings, 0, n-1, 0);
    return tree;
}

int getMaxUtil(vector<int> tree, int ss, int se, int si, int qs, int qe){
    if(ss>qe || qs>se)
        return -1;
    else if(ss>=qs && qe>=se)
        return tree[si];
    else{
        int mid = (ss+se)/2;
        int left = getMaxUtil(tree, ss, mid, (2*si)+1, qs, qe);
        int right = getMaxUtil(tree, mid+1, se, (2*si)+2, qs, qe);
        return max(left, right);
    }
}

int getMax(vector<int> tree, int n, int qs, int qe){// inclusive
    if(qe>=qs)
        return getMaxUtil(tree, 0, n-1, 0, qs, qe);
    else
        return -1;
}

void ratingPrice(vector<pair<int, int>> v, vector<pair<int, int>> queries){
    int n = (int)v.size();
    sort(v.begin(), v.end());
    
    vector<int> prices;
    vector<int> ratings;
    for(int i=0;i<n;i++){
        prices.push_back(v[i].first);
        ratings.push_back(v[i].second);
    }

    vector<int> tree = constructST(ratings);

    for(int i=0;i<(int)queries.size();i++){
        int l = lower_bound(prices.begin(), prices.end(), queries[i].first)-prices.begin();
        int r = lower_bound(prices.begin(), prices.end(), queries[i].second)-prices.begin();
        if(r<n && prices[r]!=queries[i].second)
            r--;
        
        int ans = getMax(tree, n, l, r);
        cout<<ans<<endl;
    }
}
