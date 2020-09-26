#include<bits/stdc++.h>
using namespace std;

int getByte(string s){
    int i = (int)s.size()-1;
    string str;
    while(s[i]!= ' '){
        str.push_back(s[i]);
        i--;
    }
    reverse(str.begin(), str.end());
    int no = stoi(str);
    return no;
}

void test(string filename){
    fstream fin;
    fin.open(filename, ios::in);
    
    int n=0, sum=0; 

    string line;
    int i=1;
    while(fin){
        cin.ignore()
        getline(fin, line);
        int byte = getByte(line);
        cout<<i<<": "<<line<<endl;
        // cout<<"byte: "<<byte<<endl;
        if(byte>5000){
            n++;
            sum += byte;
        }
        i++;
    }
    fin.close();

    fstream fout;
    filename = "bytes_"+filename;
    fout.open(filename, ios::out);
    fout<<n<<endl; 
    fout<<sum<<endl;
    fout.close(); 

}

int main(){
    test("input.txt");
    // test("hosts_access_log_00.txt");
}