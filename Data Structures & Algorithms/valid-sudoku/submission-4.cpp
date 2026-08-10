class Solution {
public:
    // board is a vector of rows
    bool isValidSudoku(vector<vector<char>>& board) {
        // row and column check for dups
        set<int> checked;
        for (int i = 0; i < board.size(); i++){
            for (int j = 0; j < board.size(); j++) {
                if (board.at(i).at(j) != '.') {
                    // each row check if dup
                    if (!checked.contains(board.at(i).at(j))) {
                        checked.insert(board.at(i).at(j));
                    }
                    else{
                        return false;
                    }
                }
            }
            checked.clear();
        }

        checked.clear();
        for (int i = 0; i < board.size(); i++){
            for (int j = 0; j < board.size(); j++) {
                // each col check if dup
                if (board.at(j).at(i) != '.'){
                    if (!checked.contains(board.at(j).at(i))) {
                        checked.insert(board.at(j).at(i));
                    }
                    else{
                        return false;
                    }
                }
            }
            checked.clear();
        }

        checked.clear();
        // check individual squares
        pair <int,int> topLeftCorner = {0,0};
        for (int i = 0; i < 3; i++){
            // checking rows and cols of each square
            for (int j = topLeftCorner.second; j < topLeftCorner.second+ 3; j++){
                for (int k = topLeftCorner.first; k < topLeftCorner.first+3; k++){
                    if (board.at(j).at(k) != '.'){
                        if (!checked.contains(board.at(j).at(k))) {
                            checked.insert(board.at(j).at(k));
                        }
                        else{
                            return false;
                        }
                    }
                }
            }
            checked.clear();
            if (topLeftCorner.first == 6) {
                topLeftCorner.first = 0;
                topLeftCorner.second += 3;
            }
            else{
                topLeftCorner.first += 3;
            }
        }
        return true;
    }
};
