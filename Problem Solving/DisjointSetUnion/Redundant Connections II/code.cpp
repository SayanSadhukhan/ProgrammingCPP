// Writing DSU data structure
class DSU{
    
private:
    vector<int> parent, size;
    
public:
    DSU(int n){
        for(int i = 0; i <= n; i++){
            parent.push_back(i);
            size.push_back(1);
        }
    }
    
    int findPar(int node){
        if(parent[node] == node) return node;
        
        parent[node] = findPar(parent[node]);
        return parent[node];
        
    }
    
    void unionDSU(int n, int m){
        int pn = findPar(n);
        int pm = findPar(m);
        
        if(pn == pm) return;
        
        if(size[pn] > size[pm]){
            parent[pm] = pn;
            size[pn] += size[pm];
        }
        else if(size[pn] < size[pm]){
            parent[pn] = pm;
            size[pm] += size[pn];
        }
        else{
            parent[pm] = pn;
            size[pn] += size[pm];
        }
    }
};

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int sz = edges.size();
        DSU d(sz);
        int indegree[sz + 1];
        // Populating indegree array with -1
        for(int i = 0; i <= sz; i++){
            indegree[i] = -1;
        }
        // Black list 1 and black list 2
        int bl1 = -1;
        int bl2 = -1;
        
        for(int i = 0; i < sz; i++){
            int x = edges[i][0];
            int y = edges[i][1];
            
            // Populating indegree array with the index no. of the edge responsible for 
            // making indegree 1
            if(indegree[y] == -1 ){
                indegree[y] = i;
            }
            else{
            // bl2 = indOfEdges responsible for making indegree 2
            // bl1 = indOfEdges resp. for making indegree 1    
                bl2 = i;
                bl1 = indegree[y];
                break;
                 }
        }
        
        for(int i = 0; i < sz; i++){
            if(i == bl2){
                continue;
            }
            
            int x = edges[i][0];
            int y = edges[i][1];
            // IF CYCLE is found
            if(d.findPar(x) == d.findPar(y)){    // Two cases to check:       
                if(bl2 == -1){             
                    return edges[i];                      // i) Two parent not found
                }
                else{                                     // ii) Two parent found
                    return edges[bl1];
                }
            }
            // IF cycle not found just UNION 
            else{
                
                d.unionDSU(x,y);
            }
        }
        
        return edges[bl2];
    }
};