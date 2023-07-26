class Solution {
public:
    bool search(int i,int j,int ind,vector<vector<char>>& board, string word){
        
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() )
            return false;
            
        if(ind==word.size())
            return true;
        
        bool ans=false;
        
        char ch=board[i][j];
        board[i][j]='*';
        
        if(ch==word[ind])
            ans=search(i-1,j,ind+1,board,word) || search(i,j+1,ind+1,board,word) || search(i,j-1,ind+1,board,word)
            || search(i+1,j,ind+1,board,word);
        board[i][j]=ch;
         return ans;   
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(board[i][j]==word[0]){
                    if(word.size()==1)
                        return true;
                    if(search(i,j,0,board,word))
                        return true;
                }
            
            }
        }
        return false;
    }
};