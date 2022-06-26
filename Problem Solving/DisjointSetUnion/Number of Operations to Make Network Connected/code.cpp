// Problem Link: https://leetcode.com/problems/number-of-operations-to-make-network-connected/

// Creating DSU
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
  
    void union_DSU(int n, int m){
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        int operation = 0;
        DSU d(n-1);
        vector<pair<int, int>> extra_roads;
        
        // Finding edges that are making cycle or finding extra roads
        for(auto it: connections){
            if(d.findPar(it[0]) == d.findPar(it[1])){
                extra_roads.push_back({it[0], it[1]});
            }
            else{
                d.union_DSU(it[0], it[1]);
            }
        }
        
        
        int roads_req = 0;
        int no_of_comp = 0;
        
        // Finding no. of components in DSU
        set<int> st;
        for(int i = 0; i < n; i++){
            st.insert(d.findPar(i));
        }
        
        no_of_comp = st.size();
        
        // IF all the nodes are already connected return 0
        if(no_of_comp == 1) return 0;
        
        // Required roads is always equals to no. of components - 1;
        roads_req = no_of_comp - 1;
        operation = roads_req;
        
        // If we have extra roads less than no of distinct compnt.
        if(extra_roads.size() < operation) return -1;
        
        return operation;
    }
};