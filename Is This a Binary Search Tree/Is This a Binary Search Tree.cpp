struct Node {
		int data;
		Node* left;
		Node* right;
	} 
int ChecBST(Node*root, Node*nodeLeft, Node*nodeRight) { 
    if (root == NULL) return 1;  
    if (nodeLeft != NULL && root->data <= nodeLeft->data) return 0;  
    if (nodeRight != NULL && root->data >= nodeRight->data) return 0; 
    return ChecBST(root->left, nodeLeft, root) && ChecBST(root->right, root, nodeRight); 
}
bool checkBST(Node* root) {
		Node*root1 = NULL;  
    Node*root2 = NULL;  
    if (ChecBST(root, root1, root2) == 0) return false;  
    else  return true; 
	}