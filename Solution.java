
import java.util.Arrays;

public class Solution {

    public int minFallingPathSum(int[][] matrix) {

        final int rows = matrix.length;
        final int columns = matrix[0].length;
        int[] minPathSum = Arrays.copyOf(matrix[0], columns);

        for (int r = 1; r < rows; ++r) {

            int[] currentPathSum = new int[columns];
            Arrays.fill(currentPathSum, Integer.MAX_VALUE);

            for (int c = 0; c < columns; ++c) {
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

        return Arrays.stream(minPathSum).min().getAsInt();
    }
}
