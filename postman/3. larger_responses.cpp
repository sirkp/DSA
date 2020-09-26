// larger responses
long long int getByte(string s){
    int i = (int)s.size()-1;
    string str;
    while(s[i]!= ' '){
        str.push_back(s[i]);
        i--;
    }
    reverse(str.begin(), str.end());
    long long int no = stoll(str, nullptr, 10);
    return no;
}

void largerResponses(string filename){
    fstream fin;
    fin.open(filename, ios::in);
    
    int n=0;
    long long int sum = 0; 

    string line;
    while(true){
        getline(fin, line);
        long long int byte = getByte(line);
        
        if(byte>5000){
            n++;
            sum += byte;
        }
        
        if(fin.eof())
            break;
    }
    fin.close();

    fstream fout;
    filename = "bytes_"+filename;
    fout.open(filename, ios::out);
    fout<<n<<endl; 
    fout<<sum<<endl;
    fout.close(); 

}