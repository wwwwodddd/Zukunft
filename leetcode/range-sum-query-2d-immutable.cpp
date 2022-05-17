class NumMatrix {
public:
    vector<vector<int>> s;
    NumMatrix(vector<vector<int>>& a) {
        s.resize(a.size() + 1);
        s[0].resize(a[0].size() + 1);
        for (int i = 0; i < a.size(); i++)
        {
            s[i + 1].resize(a[i].size() + 1);
            for (int j = 0; j < a[i].size(); j++)
            {
                s[i + 1][j + 1] = s[i + 1][j] + s[i][j + 1] - s[i][j] + a[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        row2++;
        col2++;
        return s[row2][col2] - s[row2][col1] - s[row1][col2] + s[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */