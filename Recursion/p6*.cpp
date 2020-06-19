// https://practice.geeksforgeeks.org/problems/tower-of-hanoi-1587115621/1/?track=SPCF-Recursion&batchId=154
void toh(int N, int from, int to, int aux, long long &moves) {
    if(N==1){
        cout<<"move disk "<<N<<" from rod "<<from<<" to rod "<<to<<endl;
        moves++;
        return;
    }
    toh(N-1, from, aux, to, moves);
    cout<<"move disk "<<N<<" from rod "<<from<<" to rod "<<to<<endl;
    moves++;
    toh(N-1, aux, to, from, moves);
}