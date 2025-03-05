class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int x = image[sr][sc];
        func(image,sr,sc,color,x);
        return image;
    }

private:
    void func(vector<vector<int>>& image, int sr, int sc, int color,int x) {
        if(sr<0 || sc<0 || sr>=image.size() || sc>=image[0].size() || image[sr][sc]==color ){
            return ;
        }
        else if(image[sr][sc]==x){
            image[sr][sc]=color;
        }
        else
        return ;
         func(image,sr-1,sc,color,x);
         func(image,sr+1,sc,color,x);
         func(image,sr,sc+1,color,x);
         func(image,sr,sc-1,color,x);
    }
   
};