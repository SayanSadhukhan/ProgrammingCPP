// Problem Link: https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<long long>> dist(n, vector<long long> (n, INT_MAX ));
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i==j) dist[i][j] = 0;
            }
        }
        
        for(auto it: edges){
            int r = it[0];
            int c = it[1];
            int wt = it[2];
            dist[r][c] = wt;
            dist[c][r] = wt;
        }
        
        //  for(int i = 0; i < n; i++){
        //     for(int j = 0; j< n; j++){
        //         cout<<dist[i][j]<<" "; 
        //     }
        //     cout<<endl;
        // }
        
       for(int k = 0; k < n; k++){
           for(int i = 0; i < n; i++){
               for(int j = 0; j < n; j++){
                       if(dist[i][k] != INT_MAX and dist[k][j] != INT_MAX ){
                           dist[i][j] = min(dist[i][j], (dist[i][k] + dist[k][j]));
                       }
                   
               }
           }
       }
        
//         for(int i = 0; i < n; i++){
//             for(int j = 0; j< n; j++){
//                 cout<<dist[i][j]<<" "; 
//             }
//             cout<<endl;
//         }
        
        int cnt = 0;
        vector<int> cities(n,-1);
        int mini = INT_MAX;
        
        for(int i = 0; i < n; i++){
            int cnt = 0;
            for(int j = 0; j < n; j++){
                if(dist[i][j] <= distanceThreshold and i!=j) cnt++;
            }
            mini = min(mini, cnt);
            cities[i] = cnt;
        }
      //  cout<<mini<<endl;
        int city = 0;
        for(int i = 0; i < n; i++){
            if(cities[i] == mini) city = i;
        }
        
        
        return city;
    }
};