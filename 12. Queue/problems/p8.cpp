// https://practice.geeksforgeeks.org/problems/circular-tour-1587115620/1/?track=SPC-Queue&batchId=154
int tour(petrolPump p[],int n){
    for(int i=0;i<n;i++)
        p[i].petrol -= p[i].distance;
    
    int minus = 0;
    int sum = 0;
    int index = 0;
    for(int i=0;i<n;i++){
        if(sum<0){
            minus += sum;
            index = i;
            sum = 0;
        }
        sum += p[i].petrol;
    }
    if((sum+minus)<0)
        return -1;
    else
        return index;

}
