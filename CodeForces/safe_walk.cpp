#include <bits/stdc++.h>;
using namespace std ;
class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size() ;
        int n = grid[0].size() ;

        vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}} ;

        queue<pair<pair<int, int>, int>> q ;
        q.push({{0,0}, health}) ;

        vector<vector<
    }
};