#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    ifstream infile("cowtip.in");
    ofstream outfile("cowtip.out");

    int N;
    infile >> N;
    
    vector<vector<int>> grid(N, vector<int>(N));
    
    for (int i = 0; i < N; ++i) {
        string row;
        infile >> row;
        for (int j = 0; j < N; ++j) {
            grid[i][j] = row[j] - '0';
        }
    }
    
    infile.close(); 
    
    int operations = 0;
    
    for (int i = N - 1; i >= 0; --i) {
        for (int j = N - 1; j >= 0; --j) {
            if (grid[i][j] == 1) {
                operations++;
                for (int x = 0; x <= i; ++x) {
                    for (int y = 0; y <= j; ++y) {
                        grid[x][y] = 1 - grid[x][y]; 
                    }
                }
            }
        }
    }
    
    outfile << operations << endl;
    outfile.close(); 
    
    return 0;
}
