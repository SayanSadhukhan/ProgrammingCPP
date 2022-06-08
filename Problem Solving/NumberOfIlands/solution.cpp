#include<bits/stdc++.h>
using namespace std;


class Solution {
    
private: void bfs(int row, int col, vector<vector<char>>& grid){
    queue<pair<int, int>> q;
    q.push({row, col});
    grid[row][col] = '$';
    
    
    int dy[] = {-1, 0, 1, 0};
    int dx[] = {0, 1, 0, -1};
    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; i++){
            int newR = r + dy[i];
            int newC = c + dx[i];
            if(newR >= 0 and newR < grid.size() and newC >= 0 and newC < grid[0].size() and grid[newR][newC] == '1'){
                grid[newR][newC] = '$';
                q.push({newR, newC});
            }
        }
    }
}    
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1'){
                    cnt++;
                    bfs(i,j, grid);
                }
            }
        }
        return cnt;
    }
};

int main(){

    vector<vector<char>> grid;
    

    Solution s;
    cout<<s.numIslands(grid);

    return 0;
}