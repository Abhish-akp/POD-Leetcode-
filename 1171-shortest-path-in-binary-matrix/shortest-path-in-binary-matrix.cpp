class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int size=grid.size();
        int n=grid[0].size();
        if(grid[0][0]!=0){
            return -1;
        }
        vector<vector<int>>vis(size,vector<int>(n,0));
        vector<pair<int,int>>vec={{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1}};
        queue<pair<pair<int,int>,int>>q;
        int moment=1;
        q.push({{0,0},1});
        while(!q.empty()){
            
            pair<pair<int,int>,int> temp=q.front();
            q.pop();
            pair<int,int>store=temp.first;
            int x=store.first;
            int y=store.second;
            moment = temp.second;
            if(x==size-1 && y==size-1){
                return moment;
            }
            for(int i=0;i<vec.size();i++){
                int dis_x=x+vec[i].first;
                int dis_y=y+vec[i].second;
                if(valid(dis_x,dis_y,size)&& grid[dis_x][dis_y]==0){
                    q.push({{dis_x,dis_y},moment+1});
                    grid[dis_x][dis_y]=1;
                }
            }
        }
        return -1;
    }
private:
    bool valid(int x,int y,int size){
        if(x>=0 && y>=0 && x<size && y<size){
            return 1;
        }
        return 0;
    }
};