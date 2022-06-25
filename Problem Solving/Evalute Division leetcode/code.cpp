
// Problem Link: https://leetcode.com/problems/evaluate-division/submissions/


class Solution {
    
private: void dfs(string src, string des, map<string, vector<pair<string, double>>> &g, set<string> vis, double &ans, double temp ){
    
    // It means the src node is already visited so return
    if(vis.find(src) != vis.end()) return;
    
    // Marking s as visisted by puting it inside visited set
    vis.insert(src);
    
    if(src == des) {
        ans = temp;
     //   cout<<ans<<endl;
        return;
    }
    else{
        for(auto it: g[src]){
            
            dfs(it.first, des, g, vis, ans, temp*it.second);
        }
    } 
}
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
       
        
      map<string, vector<pair<string, double>>> graph;
      for(int i = 0; i < equations.size(); i++){
          graph[equations[i][0]].push_back({equations[i][1], values[i]});
          graph[equations[i][1]].push_back({equations[i][0], 1/values[i]});
      }
        
      vector<double> result;
      for(int j = 0; j<queries.size(); j++){
          string s = queries[j][0];
          string d = queries[j][1];
          double ans = -1.0;
          
          set<string> vis;
          
          
          if(graph.find(s) != graph.end()) 
              dfs(s, d, graph,vis, ans, 1.0);          
    
          result.push_back(ans);
      }  
        
      
      return result;
    }
};