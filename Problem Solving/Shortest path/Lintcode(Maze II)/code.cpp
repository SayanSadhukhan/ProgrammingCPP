
// Problem Link: https://www.lintcode.com/problem/788/


// class Solution {
// public:
//     /**
//      * @param maze: the maze
//      * @param start: the start
//      * @param destination: the destination
//      * @return: the shortest distance for the ball to stop at the destination
//      */
//     int shortestDistance(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination) {
//         // write your code here
//         int n = maze.size();
//         int m = maze[0].size();
//         priority_queue< pair<int, pair<int,int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int,int>>> > pq;

//         vector<int > dist(n*m + 1, 0);
//         for(int i = 0; i < n*m + 1; i++) dist[i] = INT_MAX;
//         dist[start[0]*m + start[1] ] = 0;
//         pq.push({0, {start[0], start[1]}});  

//         while(!pq.empty()){
//             int dis = pq.top().first;
//             int r = pq.top().second.first;
//             int c = pq.top().second.second;
//             pq.pop();

//             int dy[] = {-1, 0, 1, 0};
//             int dx[] = {0, 1, 0, -1};

//             for(int i = 0; i < 4; i++){
//                 int newR = r;
//                 int newC = c;
//                 int cnt = 0; 
//                 while(newR >= 0 and newR < n and newC >= 0 and newC < m and maze[newR][newC] == 0){
//                     newR += dy[i];
//                     newC += dx[i];
//                     cnt++;
//                 }
//                 newR -= dy[i];
//                 newC -= dx[i];
//                 cnt--;
//                 if(dis + cnt < dist[newR*m + newC] ) {
//                     dist[newR*m + newC] = dis + cnt;
//                     pq.push({dis + cnt,{newR, newC}});
//                 }

//             }

//         }

//         if(dist[destination[0]*m + destination[1]] == INT_MAX) return -1;
//         return dist[destination[0]*m + destination[1]];
//     }
// };