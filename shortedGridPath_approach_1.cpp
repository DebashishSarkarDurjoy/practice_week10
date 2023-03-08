#include <iostream>
#include <vector>
#include <set>
using namespace std;

int dfs(vector<vector<int>> &grid, int i, int j, vector<vector<bool>> &visited, int cost) {
    visited[i][j] = true;
    // base case
    if (i == grid.size()-1 && j == grid[0].size()-1) {
        return grid[i][j];
    }

    // recursive case
    // 4 way dfs search to find minimum cost
    int di = {-1, 1,  0, 0};
    int dj = { 0, 0, -1, 1};
    for (int k = 0; k < 4; k++) {
        int ni = i + di[k];
        int nj = j + dj[k];

        if (ni >= 0 && nj >= 0 && ni < grid.size() && nj < grid[0].size() && !visited[ni][nj]) {
            pair<int,int> minPair = findMin(ni, nj, visited);
            cost += dfs(grid, minPair.first, minPair.second, visited, cost);
        }
    }
    return grid[ni][nj];
} 

int shortest_path(vector<vector<int> > grid){
    //return the shortest path len
    vector<vector<bool>> visited(grid.size(), vector<bool> (grid[0].size(), false));
    int cost = dfs(grid, 0, 0, visited, cost);
    
    return 0;
}

int main(void) {
    
    vector<vector<int>> grid = {
        {31, 100, 64, 12, 18},
        {10, 13, 47, 157, 6},
        {100, 113, 174, 11, 33},
        {88, 124, 41, 20, 140},
        {99, 32, 111, 41, 20}
    };

    cout << "Shortest Path Cost: " << shortest_path(grid) << endl;

    return 0;
}