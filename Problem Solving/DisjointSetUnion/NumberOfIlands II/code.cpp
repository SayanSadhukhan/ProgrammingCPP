// Problem link: https://www.lintcode.com/problem/434/

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class DSU {
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
        return parent[node] = findPar(parent[node]);
    }

    void union_DSU(int u, int v){
        int pu = findPar(u);
        int pv = findPar(v);
        if(pu == pv) return;
        if(size[pu] < size[pv]){
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else if(size[pv] < size[pu]){
            parent[pv] = pu;
            size[pu] += size[pv];
        }
        else{
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
public:
    /**
     * @param n: An integer
     * @param m: An integer
     * @param operators: an array of point
     * @return: an integer array
     */
    vector<int> numIslands2(int n, int m, vector<Point> &operators) {
        // write your code here
        vector<vector<int> > grid(n , vector<int> (m, 0));
        vector<int> ans;

        DSU d(n*m + 1);
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        int cnt = 0;
        for(auto it: operators){
            int x = it.x;
            int y = it.y;
            
            if(grid[x][y] == 1 ) {
                ans.push_back(cnt);
                continue;
            }
            grid[x][y] = 1;
            int ind1 = x*m + (y+1);

            cnt++;
            for(int i = 0; i < 4; i++){
                int newX = x + dx[i];
                int newY = y + dy[i];
                int ind2 = newX*m + (newY + 1);
                if(newX >= 0 and newX < n and newY >= 0 and newY < m and grid[newX][newY] == 1 and d.findPar(ind1) != d.findPar(ind2)){
                        d.union_DSU(ind1, ind2);
                        cnt--;
                }
            }
            ans.push_back(cnt);
        }        

        return ans;

    }
};