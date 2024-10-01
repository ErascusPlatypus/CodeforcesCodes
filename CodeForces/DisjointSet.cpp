#include <bits/stdc++.h>
using namespace std ;

class DisjointSet {
    vector<int> rank, parent, size ;

    public:
        DisjointSet(int n) {
            rank.resize(n+1, 0); 
            parent.resize(n+1);
            size.resize(n+1); 
            for(int i = 0;i<=n;i++) {
                parent[i] = i; 
                size[i] = 1; 
            }
        }

        int findUP(int node) {
            if(node == parent[node]) {
                return node ;
            }

            return parent[node] = findUP(parent[node]) ;
        }

        void unionrank(int u, int v) {
            int up_u = findUP(u) ;
            int up_v = findUP(v) ;

            if(up_v == up_u) {
                return ;
            }

            if(rank[up_u] < rank[up_v]) {
                parent[up_u] = up_v ;
            }
            else if(rank[up_v] < rank[up_u]) {
                parent[up_v] = up_u ;
            }
            else {
                parent[up_v] = up_u ;
                rank[up_u]++ ; 
            }
        }

        void unionsize(int u, int v) {
            int up_u = findUP(u) ;
            int up_v = findUP(v) ;

            if(up_v == up_u) {
                return ;
            }

            if(size[up_u] < size[up_v]) {
                parent[up_u] = up_v ;
                size[up_v] += size[up_u] ;
            }
            else {
                parent[up_v] = up_u ;   
                size[up_u] += size[up_v] ;
            }
        }
};

int main() {
    DisjointSet ds(7) ;
    // ds.unionrank(1 ,2) ;
    // ds.unionrank(2 ,3) ;
    // ds.unionrank(4 ,5) ;
    // ds.unionrank(6, 7) ;
    // ds.unionrank(5, 6) ;

    ds.unionsize(1 ,2) ;
    ds.unionsize(2 ,3) ;
    ds.unionsize(4 ,5) ;
    ds.unionsize(6, 7) ;
    ds.unionsize(5, 6) ;

    if(ds.findUP(3) == ds.findUP(7)) {
        cout << "Same\n" << endl ;
    }
    else cout << "NOT SAME\n" << endl ; 

    ds.unionrank(3, 7) ;

    if(ds.findUP(3) == ds.findUP(7)) {
        cout << "Same\n" << endl ;
    }
    else cout << "NOT SAME\n" << endl ; 

    return 0 ; 
}