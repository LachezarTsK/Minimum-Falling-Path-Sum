
/**
 * @param {number[][]} matrix
 * @return {number}
 */
var minFallingPathSum = function (matrix) {

    const rows = matrix.length;
    const columns = matrix[0].length;
    let minPathSum = Array.from(matrix[0]);

    for (let r = 1; r < rows; ++r) {

        const currentPathSum = new Array(columns).fill(Number.MAX_SAFE_INTEGER);

        for (let c = 0; c < columns; ++c) {
            currentPathSum[c] = Math.min(currentPathSum[c], minPathSum[c] + matrix[r][c]);
            if (c - 1 >= 0) {
                currentPathSum[c] = Math.min(currentPathSum[c], minPathSum[c - 1] + matrix[r][c]);
            }
            if (c + 1 < columns) {
                currentPathSum[c] = Math.min(currentPathSum[c], minPathSum[c + 1] + matrix[r][c]);
            }
        }

        minPathSum = currentPathSum;
    }

    return Math.min(...minPathSum);
};
