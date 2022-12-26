
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    
public:
    //C++20: int minFallingPathSum(span<const vector<int>> matrix) const 
    int minFallingPathSum(const vector<vector<int>>& matrix) const {
        
        const size_t rows = matrix.size();
        const size_t columns = matrix[0].size();
        vector<int> minPathSum{ matrix[0].begin(), matrix[0].end()};

        for (size_t r = 1; r < rows; ++r) {

            vector<int> currentPathSum(columns, INT_MAX);

            for (size_t c = 0; c < columns; ++c) {
                currentPathSum[c] = min(currentPathSum[c], minPathSum[c] + matrix[r][c]);
                if (c - 1 != variant_npos) {
                    currentPathSum[c] = min(currentPathSum[c], minPathSum[c - 1] + matrix[r][c]);
                }
                if (c + 1 < columns) {
                    currentPathSum[c] = min(currentPathSum[c], minPathSum[c + 1] + matrix[r][c]);
                }
            }

            minPathSum = move(currentPathSum);
        }

        //C++20: *std::ranges::min_element(minPathSum);
        return *min_element(minPathSum.begin(), minPathSum.end());
    }
};
