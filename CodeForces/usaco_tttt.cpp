#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

using namespace std;

bool isIndividualWinner(char cow, const vector<string>& board) {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == cow && board[i][1] == cow && board[i][2] == cow)
            return true;
    }

    for (int j = 0; j < 3; ++j) {
        if (board[0][j] == cow && board[1][j] == cow && board[2][j] == cow)
            return true;
    }

    if ((board[0][0] == cow && board[1][1] == cow && board[2][2] == cow) ||
        (board[0][2] == cow && board[1][1] == cow && board[2][0] == cow))
        return true;

    return false;
}

bool isTeamWinner(char cow1, char cow2, const vector<string>& board) {
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == cow1 || board[i][0] == cow2) &&
            (board[i][1] == cow1 || board[i][1] == cow2) &&
            (board[i][2] == cow1 || board[i][2] == cow2))
            return true;
    }

    for (int j = 0; j < 3; ++j) {
        if ((board[0][j] == cow1 || board[0][j] == cow2) &&
            (board[1][j] == cow1 || board[1][j] == cow2) &&
            (board[2][j] == cow1 || board[2][j] == cow2))
            return true;
    }

    if (((board[0][0] == cow1 || board[0][0] == cow2) &&
         (board[1][1] == cow1 || board[1][1] == cow2) &&
         (board[2][2] == cow1 || board[2][2] == cow2)) ||
        ((board[0][2] == cow1 || board[0][2] == cow2) &&
         (board[1][1] == cow1 || board[1][1] == cow2) &&
         (board[2][0] == cow1 || board[2][0] == cow2)))
        return true;

    return false;
}

int main() {
    ifstream fin("tttt.in");
    ofstream fout("tttt.out");

    vector<string> board(3);
    for (int i = 0; i < 3; ++i) {
        fin >> board[i];
    }

    int individualCount = 0;
    int teamCount = 0;

    unordered_map<char, bool> checked;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            char cow = board[i][j];
            if (!checked[cow] && isIndividualWinner(cow, board)) {
                individualCount++;
                checked[cow] = true;
            }
        }
    }

    checked.clear();
    for (char cow1 = 'A'; cow1 <= 'Z'; ++cow1) {
        for (char cow2 = cow1 + 1; cow2 <= 'Z'; ++cow2) {
            if (!checked[cow1] && !checked[cow2] && isTeamWinner(cow1, cow2, board)) {
                teamCount++;
                checked[cow1] = true;
                checked[cow2] = true;
            }
        }
    }

    fout << individualCount << endl;
    fout << teamCount << endl;

    fin.close();
    fout.close();

    return 0;
}
