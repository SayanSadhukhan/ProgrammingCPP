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
    
    void union_DSU(int m, int n){
        int pm = findPar(m);
        int pn = findPar(n);
        
        if(pm == pn) return;
        
        if(size[pm] > size[pn]){
            parent[pn] = pm;
            size[pm] += size[pn];
        }
        else if(size[pm] < size[pn]){
            parent[pm] = pn;
            size[pn] += size[pm];
        }
        else{
            parent[pn] = pm;
            size[pm] += size[pn];
        }
            
        }
    };


class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        // First we make a DSU of size = Number of alphabets present(A-Z)
        DSU d(25);
        
        // Union those alphabets which equals to the other
        for(string s: equations){
            if(s[1] == '='){
            
                d.union_DSU(s[0] - 'a', s[3] - 'a');
            }
        }
        
        // Now check if a!=b but a & b belong to the same component, then return false
        for(string s: equations){
            if(s[1] == '!'){
                if(d.findPar(s[0] - 'a') == d.findPar(s[3] - 'a')) return false;
            }
        }
        return true;
    }
};