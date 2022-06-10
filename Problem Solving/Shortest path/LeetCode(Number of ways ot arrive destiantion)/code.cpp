
// Problem link: https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/

// class Solution {
// public:
//     int countPaths(int n, vector<vector<int>>& roads) {
//         long long mod =( 1e9 + 7);
        
//         long long maxi = 1e18;
//         vector<long long> dist(n, maxi);
//         vector<long long> ways(n, 0);
//         dist[0] = 0;
//         ways[0] = 1;
        
//         vector<pair<long long, long long>> adj[n];
//         for(auto it: roads){
//             adj[it[0]].push_back({it[1], it[2]});
//             adj[it[1]].push_back({it[0], it[2]});
//         }
        
//         priority_queue< pair<long long, long long>, 
//         vector<pair<long long, long long>> , greater<pair<long long, long long>>> pq;
//         pq.push({0, 0});
        
//         while(!pq.empty()){
//             long long node = pq.top().second;
//             long long dis = pq.top().first;
//             pq.pop();
            
//             for(auto it: adj[node]){
//                 long long n2 = it.first;
//                 long long wt = it.second;
//                 if(dis + wt < dist[n2] ){
                    
//                     dist[n2] = dis + wt;
//                     pq.push({dist[n2], n2});
//                     ways[n2] = ways[node];
//                 }
//                 else if( dis + wt == dist[n2]) {
//                     ways[n2] = (ways[n2] + ways[node]) % mod;
//                 }
//             }
//         }
//         return ways[n-1];
//     }
// };