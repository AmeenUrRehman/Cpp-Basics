class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	vector<int> result;
    	if(root == NULL){
    	    return result;
    	}
    	queue<Node*> q;
    	q.push(root);
    	
    	bool LeftToRight = true;
    	
    	while(!q.empty()){
    	    //Level Process
    	    int size = q.size();
    	    vector<int> ans(size);
    	   
    	    // Level Traverse
    	    for(int i =0 ; i <size ; i++){
    	        Node* frontNode = q.front();
    	        q.pop();
    	    
        	    
        	    int index = LeftToRight ? i : size - i - 1;
        	    ans[index] = frontNode -> data;
        	    
        	    if(frontNode -> left){
        	        q.push(frontNode -> left);
        	    }
        	    if(frontNode -> right){
        	        q.push(frontNode -> right);
        	    }
    	    }
    	    
    	    LeftToRight = !LeftToRight;
    	    
    	    for(auto i : ans){
    	        result.push_back(i);
    	    }
    	}
    	return result;
    	
    }
};