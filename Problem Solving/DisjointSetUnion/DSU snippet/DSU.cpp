#include <bits/stdc++.h>
using namespace std;

#define ll long long int


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




void file_i_o()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}






int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();
    // Write your code here....
    DSU d(5);
    cout<<"d.findPar(1): "<<d.findPar(1)<<endl;
    cout<<"d.findPar(2): "<<d.findPar(2)<<endl;
    cout<<"d.findPar(3): "<<d.findPar(3)<<endl;
    cout<<"d.findPar(5): "<<d.findPar(5)<<endl;

    cout<<"d.DSU_union(1,5) "<<endl;
    d.DSU_union(1,5);
    cout<<"\n"<<"d.findPar(5):\t\t"<<d.findPar(5)<<endl;
    cout<<"d.findPar(4):\t\t"<<d.findPar(4)<<endl;
    cout<<"\nd.DSU_union(3,2):\t\t"<<endl;
    d.DSU_union(3,2);
    cout<<"d.findPar(2):\t\t"<<d.findPar(2)<<endl;
    cout<<"\nd.DSU_union(2,4): "<<endl;
    d.DSU_union(2,4);
    cout<<"d.findPar(4):\t\t"<<d.findPar(4)<<endl;
    cout<<"\nd.DSU_union(4,5): "<<endl;
    d.DSU_union(4,5);
    cout<<"d.findPar(5):\t\t"<<d.findPar(5)<<endl;
    

    #ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\n Executed In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
    return 0;
}