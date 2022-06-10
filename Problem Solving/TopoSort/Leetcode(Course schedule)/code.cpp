//Problem Link: https://leetcode.com/problems/course-schedule/ 


//class Solution {
//     private: bool dfs(int n, vector<int> adj[], vector<int> &vis, vector<int> &pathVis){
//         vis[n] = 1;
//         pathVis[n] = 1;
//         for(auto it: adj[n]){
//             if(!vis[it]){
//                 if(dfs(it, adj, vis, pathVis)) return true;
//             }
//             else if(vis[it] == 1 and pathVis[it] == 1) return true;
//         }
//         pathVis[n] = 0; 
//         return false;
//     }
// public:
//     bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//         int v = numCourses;
//         vector<int> vis(v, 0), pathVis(v, 0);
//         vector<int> adj[v];
//         for (auto it: prerequisites){
//             adj[it[0]].push_back(it[1]);
//         }
        
//         for(int i = 0; i < v; i++){
//             for(auto it: adj[i]){
//                 if(!vis[it]) 
//                     {
//                       if(dfs(it, adj, vis, pathVis)) return false;
//                     }
//                 }
//         }
//         return true;
//     }
    
// };