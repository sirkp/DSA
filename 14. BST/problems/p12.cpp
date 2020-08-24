// https://practice.geeksforgeeks.org/problems/implementing-floor-in-bst/1/
int floor(Node* root, int key) { 
	if(root){
	    // if(key==root->data)
	    //     return root->data;
	    if(key<root->data){
	        return floor(root->left, key);
	    }else{
	        int r = floor(root->right, key);
	        return max(r, root->data);
	    }
	}else
	    return -1;
}