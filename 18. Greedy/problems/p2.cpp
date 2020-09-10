// https://practice.geeksforgeeks.org/problems/huffman-decoding/1/?track=DSASP-Greedy&batchId=154
string decodeHuffmanData(struct MinHeapNode* root, string binaryString){
    string s = "";
    
    MinHeapNode* node = root;
    for(int i=0;i<(int)binaryString.size();i++){
        if(binaryString[i]=='0')
            node = node->left;
        else
            node = node->right;
        if(node->left==NULL && node->right==NULL){
            s += node->data;
            node = root;
        }
    }
    return s;
}