#include <bits/stdc++.h>
using namespace std;

int findup(int node, vector<int>& parent) {
    if(parent[node] == node) return node ;

    return parent[node] = findup(parent[node], parent) ;
}

void unionsize(int u, int v, vector<int>& parent, vector<int>& size) {
    int upu = findup(u, parent), upv = findup(v, parent) ; 
    if(upu == upv) return ; 

    if(size[upu] > size[upv]) {
        parent[upv] = upu ; 
        size[upu] += size[upv] ;
    }
    else {
        parent[upu] = upv ;
        size[upv] += size[upu] ;
    }
}


int32_t main() {
    int t ;
    cin >> t ;

    while(t--) {
        int n, m ; 
        cin >> n >> m ; 

        vector<int> parent(n*m), size(n*m, 1) ;
        vector<vector<int>> graph(n, vector<int>(m, 0)) ; 
        vector<pair<int, int>> cells ; 
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                cin >> graph[i][j] ;
                if(graph[i][j] > 0) {
                    cells.emplace_back(i, j) ;
                }
            }
        }

        for(int i = 0 ; i < n*m ; i++) {
            parent[i] = i ; 
        }

        vector<pair<int, int>> dirs = {{0, -1}, {1, 0}, {-1, 0}, {0, 1}} ;
        
        for(auto [i, j] : cells) {
            for(auto d : dirs) {
                int x = i + d.first, y = j + d.second; 
                if(x >= 0 && y >= 0 && x < n && y < m) {
                    if(graph[x][y] > 0) {
                        unionsize(i*m + j, x*m + y, parent, size) ;
                    }
                }
            }
        }

        vector<int> vol(n*m, 0) ;
        for(auto [i, j] : cells) {
            vol[findup(i*m+j, parent)] += graph[i][j] ;
        }

        int maxi = *max_element(vol.begin(), vol.end()) ;

        cout << maxi << endl ;
    }
    return 0;
}