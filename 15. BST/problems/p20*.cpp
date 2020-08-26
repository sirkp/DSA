// https://practice.geeksforgeeks.org/problems/smaller-on-right/0/
int smallerOnRight(int arr[], int n){
    set<int> s;
    int ans = 0;
    for(int i=(n-1);i>=0;i--){
        s.insert(arr[i]);
        auto it = s.find(arr[i]);
        int c = distance(s.begin(), it);// complexity O(1) for random access iterator and O(1) for bidirectional iterator
        ans = max(ans, c);
    }
    return ans;
}
// random access iterator: vector, dequeue
// bidirectional iterator: list, set, multiset, map, multimap