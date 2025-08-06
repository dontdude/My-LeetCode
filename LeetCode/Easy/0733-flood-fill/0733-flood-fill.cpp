class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] == color)  return image;

        int m = image.size(), n = image[0].size();
        int startpixel = image[sr][sc];
        vector<vector<int>> filled = image;
        queue<pair<int, int>> q;
        q.push({sr, sc});

        while(!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            filled[i][j] = color;

            for(int k = 0; k < 4; k++) {
                int x = i + dx[k];
                int y = j + dy[k];

                if(((x >= 0 && x < m) && (y >= 0 && y < n)) && filled[x][y] == startpixel) {
                    q.push({x, y});
                }
            }
        }
         
        return filled;
    }
};