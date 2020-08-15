import java.util.*;
import java.lang.Math;


class Solution {
    public boolean findNumberIn2DArray(int[][] matrix, int target) {
        /*for (int[] i: matrix){
            for (int j: i){
                if (target == j){
                    return true;
                }
            }
        }
        return false;
        */

        if (matrix.length <= 0 || matrix[0].length <= 0){
            return false;
        }

        int pivotRow = matrix.length - 1;
        int pivotCol = 0;
        while (pivotRow >= 0 && pivotCol < matrix[0].length){
            if (target == matrix[pivotRow][pivotCol]){
                return true;
            }
            if (target < matrix[pivotRow][pivotCol]){
                pivotRow--;
            }
            else if (target > matrix[pivotRow][pivotCol]){
                pivotCol++;
            }
        }
        return false;

    }
}