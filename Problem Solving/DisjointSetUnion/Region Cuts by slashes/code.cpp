// Problem link: https://leetcode.com/problems/regions-cut-by-slashes/submissions/
// Leetcode: Medium

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
    
    void unionDSU(int a, int b){
        int pa = findPar(a);
        int pb = findPar(b);
        
        if(pa == pb) return;
        
        if(size[pa] > size[pb]){
            parent[pb] = pa;
            size[pa ] += size[pb];
        }
        else if(size[pb] > size[pa]){
            parent[pa] = pb;
            size[pb] += size[pa];
        }
        else{
            parent[pb] = pa;
            size[pa ] += size[pb];
        }
    }
};

class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int cnt = 1;
        int n = grid.size();
        int dots = n + 1;
        DSU d(dots*dots);
        
        for(int i = 0; i < dots; i++){
            for(int j = 0; j < dots; j++){
                if(i == 0 or j == 0 or i == dots - 1 or j == dots - 1){
                    int dotNO = i*n + j;
                    d.unionDSU(0, dotNO);
                }
            }
        }
        
        for(int i = 0; i < n; i++){
            auto &str = grid[i];
            for(int j = 0; j< str.length(); j++){
                if(str[j] == '/'){
                    int point1 = i*n + (j+ 1);
                    int point2 = (i+1)*n + j;
                    
                    int par_point1 = d.findPar(point1);
                    int par_point2 = d.findPar(point2);
                    if(par_point1 == par_point2) cnt++;
                    else{
                        d.unionDSU(point1, point2);
                    }
                }
                else if(str[j] == '\\'){
                    int point1 = i*n + j;
                    int point2 = (i+1)*n + (j+1);
                    
                    int par_point1 = d.findPar(point1);
                    int par_point2 = d.findPar(point2);
                    if(par_point1 == par_point2) cnt++;
                    else{
                        d.unionDSU(point1, point2);
                    }
                    
                }
            }
        }
        
        return cnt;
    }
};