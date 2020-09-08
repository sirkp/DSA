// optimal storage on tapes
// https://www.geeksforgeeks.org/optimal-storage-tapes/
void findOrderMRT(int L[], int n) { 
    sort(L, L + n); 
  
    for (int i = 0; i < n; i++) 
        cout << L[i] << " "; 
    cout << endl; 
  
} 