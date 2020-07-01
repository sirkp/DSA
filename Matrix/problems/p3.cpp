// https://practice.geeksforgeeks.org/problems/multiply-the-matrices-1587115620/1/?track=SPCF-Matrix&batchId=154
void multiplyMatrix(int n1, int m1, int n2, int m2, long long arr1[SIZE][SIZE], long long arr2[SIZE][SIZE]){
    
    // Your code here
    if(m1==n2){
        for(int i=0;i<n1;i++){
            for(int j=0;j<m2;j++){
                int temp = 0;
                for(int k=0;k<m1;k++){
                    temp += (int)(arr1[i][k]*arr2[k][j]);
                }
                cout<<temp<<" ";
            }
        }
    }
    else{
        cout<<(-1);
    }
}