//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int solveSOpt(vector<vector<int>> &mat, int &maxi){
        
        int row = mat.size();
        int col = mat[0].size();
        
        vector<int> curr(col + 1, 0);
        vector<int> next(col + 1, 0);
        
        for(int i = row - 1 ; i >= 0 ; i-- ){
            for(int j = col - 1; j >= 0 ; j--){
                
                int right = curr[j+1];
                int diagonal = next[j+1];
                int down = next[j];
                
                if(mat[i][j] == 1){
                   curr[j] = 1 + min(right , min(diagonal , down));
                   maxi = max(maxi , curr[j]);
                }
                else{
                    curr[j] = 0;
                }
            }
            next = curr;
        }
        
        return next[0];
    }
    int maxSquare(int n, int m, vector<vector<int>> mat){
        // code here
        
        int maxi = 0 ;
        solveSOpt(mat, maxi);
        return maxi;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n*m;i++)
            cin>>mat[i/m][i%m];
        
        Solution ob;
        cout<<ob.maxSquare(n, m, mat)<<"\n";
    }
    return 0;
}
// } Driver Code Ends