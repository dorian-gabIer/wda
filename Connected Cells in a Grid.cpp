#include <algorithm>
#include <vector>
#include <iostream>
typedef std::vector<std::vector<int>> grid_t;
int fill_region(grid_t& grid, int i, int j, int n, int m)
{
    if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] != 1) return 0;
    grid[i][j] = -1;
    int size = 1;
    for (int di = -1; di <= +1; di++)
    {
       for (int dj = -1; dj <= +1; dj++)
       {
           if (di || dj) size += fill_region(grid, i + di, j + dj, n, m);
       }
    }
    return size;
}
int max_region(grid_t& grid, int n, int m)
{
    int max = 0;
    for (int i = 0; i < n; i++)
    {
       for (int j = 0; j < m; j++)
       {
           max = std::max(max, fill_region(grid, i, j, n, m));
       }
    }
    return max;
}
int main()
{
    int n; std::cin >> n;
    int m; std::cin >> m;
    grid_t grid(n, std::vector<int>(m));
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
       {
         std::cin >> grid[i][j];
       }
    }
    std::cout << max_region(grid, n, m) << std::endl;
    return 0;
}
