class SubrectangleQueries {
    vector<vector<int>> queries;
    vector<vector<int>> base_grid;

    bool isQueryApplied(int row, int col, vector<int> query) {
        return (query[0] <= row && row <= query[2]) && (query[1] <= col && col <= query[3]);
    }
public:
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        queries.clear();
        base_grid = rectangle;
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        queries.push_back({row1, col1, row2, col2, newValue});
    }
    
    int getValue(int row, int col) {
        int n = queries.size();

        for(int i = n - 1; i >= 0; i--) {
            if(isQueryApplied(row, col, queries[i])) {
                return queries[i][4];
            }
        }

        return base_grid[row][col];
    }
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */