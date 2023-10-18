class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int>indegree(n,0);
        for(int i=0;i<n;i++){
           if(leftChild[i]!=-1) 
               indegree[leftChild[i]]++;
               if(rightChild[i]!=-1) 
               indegree[rightChild[i]]++;
        }
        
        int root=-1;
          for(int i=0;i<n;i++){
            if(indegree[i]==0){
                if(root==-1)
                    root=i;
                else 
                    return false;
            }
        }
        
         if(root==-1)
             return false;
        
        queue<int>q;
        vector<int>visited(n,false);
        
        q.push(root);
        // visited[root]=true;
        
        while(!q.empty()){
          int node=q.front();
            q.pop();
            if(visited[node])
               return false;
           
             visited[node]=true;
            if(leftChild[node]!=-1)
            q.push(leftChild[node]);
            
            if(rightChild[node]!=-1)
            q.push(rightChild[node]);
        }
        
        return accumulate(visited.begin(),visited.end(),0)==n;
    }
};