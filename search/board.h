#ifndef __BOARD_H
#define __BOARD_H

#include <vector>
#include <ncurses.h>
#include <utility>
using namespace std;
typedef pair<int, int> mv;
typedef pair<int, int> pos;

extern const char* black_char;
extern const char* white_char;
extern const char* blank_char;

const int BLACK = 1;
const int WHITE = -1;
const int BLANK = 0;
const int BOARD_SZ = 15;

// -1 for white, 0 for blank, 1 for black
class Board{
public:
	Board(int N);
	Board(int N, const vector<vector<int>>& opening);
	void draw() const;
	bool move(const mv& move, bool is_black);
	bool move_valid(const mv& move) const;
	vector<vector<int>>& get_board() { return __board;}
	vector<mv>& get_white_moves() { return __black_moves;}
	vector<mv>& get_black_moves() { return __white_moves;}
	int finish() const;
private:
	int __N;
	vector<vector<int>> __board;
	vector<mv> __black_moves;
	vector<mv> __white_moves;
    int winner;
};

#endif
