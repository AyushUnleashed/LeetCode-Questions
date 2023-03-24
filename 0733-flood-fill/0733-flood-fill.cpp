class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n =image.size();
        int m=image[0].size();
      
        if(image[sr][sc]==color) return image;
        
        int oldVal = image[sr][sc];
        if( sr+1<n && image[sr][sc]==image[sr+1][sc]){
            image[sr][sc]=color;
           floodFill(image,sr+1,sc,color);
            image[sr][sc]=oldVal;
            
        }
        if(sr-1>=0 && image[sr][sc]==image[sr-1][sc]){
             image[sr][sc]=color;
            floodFill(image,sr-1,sc,color);
            image[sr][sc]=oldVal;
        }
        if(sc-1>=0 && image[sr][sc]==image[sr][sc-1]){
             image[sr][sc]=color;
           floodFill(image,sr,sc-1,color);
            image[sr][sc]=oldVal;
        }
        if(sc+1<m && image[sr][sc]==image[sr][sc+1]){
             image[sr][sc]=color;
           floodFill(image,sr,sc+1,color);
            image[sr][sc]=oldVal;
        }
        image[sr][sc]=color;
        
        return image;
    }
};