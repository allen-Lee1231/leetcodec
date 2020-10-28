class Solution:
    def minPathSum(self, grid: list) -> int:
        # init dp map
        N = len(grid)
        M = len(grid[0])
        dp = [[0] * M for _ in range(N)]
        dp[0][0] = grid[0][0]
        for i in range(1, N):
            dp[i][0] = grid[i][0] + dp[i-1][0]
        for i in range(1, M):
            dp[0][i] = grid[0][i] + dp[0][i-1]

        for i in range(1, M):
            for j in range(1, N):
                # choose path either downward or rightward
                dp[j][i] = min(dp[j-1][i], dp[j][i-1]) + grid[j][i]
            # if can move upward
            # then choose either upward or result from last iteration above
            """
            for j in range(N-2, -1, -1):
                dp[j][i] = min(abs(grid[j+1][i] - grid[j][i]) + dp[j+1][i],
                               dp[j][i])
            """
        return dp[-1][-1]


checkerboard = [[1, 2, 4], [1, 3, 1], [4, 2, 1]]
print(Solution().minPathSum(checkerboard))