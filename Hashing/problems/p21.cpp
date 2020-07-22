// https://practice.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/1/?track=SPCF-Hashing&batchId=154
int findLongestConseqSubseq(int arr[], int n){
    unordered_set<int> hash;
    for(int i=0;i<n;i++)
        hash.insert(arr[i]);

    int count = 0, temp, c;
    for(auto x: hash){
        c = 1;
        temp = x+1;
        while(hash.find(temp)!=hash.end()){
            c++;
            hash.erase(temp);
            temp++;
        }
        temp = x-1;
        while(hash.find(temp)!=hash.end()){
            c++;
            hash.erase(temp);
            temp--;
        }
        count = max(c, count);
    }  
    return count;  
}
