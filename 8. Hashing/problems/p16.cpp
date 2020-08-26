// https://practice.geeksforgeeks.org/problems/numbers-containing-1-2-and-32555/1/?track=SPCF-Hashing&batchId=154
void findAll() {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    int i = 0;

    int no;
    while(1){
        no = v[i]*10 + 1;
        if(no>1000000)
            break;
        v.push_back(no);    
        no = v[i]*10 + 2;
        v.push_back(no);    
        no = v[i]*10 + 3;
        v.push_back(no); 
        i++;   
    }

    for(int i=0;i<(int)v.size();i++)
        mp.insert({v[i], 1});
}
