class Solution {
public:
    void dfs(vector<vector<int>>& image,int r,int c,int color,int val,int dr[],int dc[]){
        int n=image.size();
        int m=image[0].size();
        image[r][c]=color;
        for(int i=0;i<4;i++){
            int row=dr[i]+r;
            int col=dc[i]+c;
                if(row>=0 && row<n && col>=0 && col<m && image[row][col]==val && image[row][col]!=color ){
                    // image[row][col]=color;
                    dfs(image,row,col,color,val,dr,dc);
                }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
         int val=image[sr][sc];
        int dr[]={-1,0,0,1};
        int dc[]={0,-1,1,0};
        dfs(image,sr,sc,color,val,dr,dc);
        return image;
    }
};