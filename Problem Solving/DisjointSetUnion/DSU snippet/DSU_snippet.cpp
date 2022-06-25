class DSU
{
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

    void DSU_union(int n, int m){
        int pn = findPar(n);
        int pm = findPar(m);
        if(pn == pm){
            return;
        }
        else if(size[pn] > size[pm]){
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