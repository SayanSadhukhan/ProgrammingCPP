// Problem Link: https://leetcode.com/problems/as-far-from-land-as-possible/

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        vector<pair<int,int>> Num_of_one;
        int sz = grid.size();
        for(int i = 0; i< sz; i++){
            for(int j = 0; j< sz; j++){
                if(grid[i][j] == 1) Num_of_one.push_back({i,j});
            }
        }
        
        queue<pair<int, int>> q;
        for(int i = 0; i < Num_of_one.size(); i++){
            q.push(Num_of_one[i]);
        }
        
        if(q.size() == 0 or q.size() == sz*sz) return -1;
        int level = -1;
        
        
        // for traversing in all 4 directions
        // dy[0],dx[0] = up;
        // dy[1],dx[1] = right;
        // dy[2],dx[2] = down;
        // dy[3],dx[3] = left
        int dy[] = {-1, 0, 1, 0};
        int dx[] = {0, 1, 0, -1};
        
        // Multy source BFS
        while(!q.empty()){
            // keeping track of the entries in the q at each level from the src
            // At this level we have only 1s in the q, so distance is zero to any zero
            // Next level when zero enters in the q, then distance form 0 will be 1
            // Next level the dist will be 2...
            level++;
            int q_size = q.size();
            
            // Normal BFS applied here
            while(q_size-- ){
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                
                // Traversing at 4 directions
                for(int i = 0; i < 4; i++){
                    int newR = r + dy[i];
                    int newC = c + dx[i];
                    
                    
                    // Taking care of the Out of bound cases and visited cases
                    if(newR >= 0 and newC >= 0 and newR < sz and newC < sz and grid[newR][newC] != 1 ){
                        q.push({newR, newC});
                        
                        // Keeps track of the visited cells
                        grid[newR][newC] = 1;
                    }
                }
            }
        }
        return level;
    }
};