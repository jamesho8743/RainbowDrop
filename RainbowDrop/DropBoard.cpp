#include "stdafx.h"
#include "DropBoard.h"
#include <random>
#include <iostream>
#include <iomanip>

using namespace std;

ostream& operator<<(ostream& os, const DropColors& color)	// Operator Overloading should put before where it actually used
{
	char ch;
	switch (color) {
	case FIRE:
		ch = 'R';
		break;

	case WATER:
		ch = 'B';
		break;

	case WOOD:
		ch = 'G';
		break;

	case LIGHT:
		ch = 'W';
		break;

	case DARK:
		ch = 'D';
		break;

	case HEART:
		ch = 'H';
		break;

	}
	os << ch;
	return os;
}

DropBoard::DropBoard() {
	random_device rd;   // non-deterministic generator
	mt19937 gen(rd());  // to seed mersenne twister.
						// replace the call to rd() with a
						// constant value to get repeatable
						// results.
	uniform_int_distribution<> dist(FIRE, HEART); // distribute results between 1 and 6 inclusive.

	for (auto &row : m_board) {
		for ( auto &col : row )
			col = static_cast<DropColors>( dist(gen) );
	}

	for (auto &row : m_board) {
		for (auto &col : row)
			cout << col << " ";
		cout << endl;
	}

// C++ random
// https://msdn.microsoft.com/zh-tw/library/bb982398.aspx

	// Fill BitBoard
	m_fire = new BitBoard(m_board, FIRE);
	m_water = new BitBoard(m_board, WATER);
	m_wood = new BitBoard(m_board, WOOD);
	m_light = new BitBoard(m_board, LIGHT);
	m_dark = new BitBoard(m_board, DARK);
	m_heart = new BitBoard(m_board, HEART);

	//cout.setf(ios::hex, ios::basefield);
	//cout.width(16);
	cout << "FIRE " << "0x" << hex << uppercase << setfill('0') << setw(16) << m_fire->getValue();

}

BitBoard::BitBoard(DropColors (&Board)[BOARD_HEIGHT][BOARD_WIDTH], DropColors Color ) {
	m_value = 0;
	int i = 0;
	int j = 0;
	for (auto &row : Board) {
		for (auto &col : row) {
			if (col == Color)
				m_value += (1i64 << (j * 8 + i)); // Using 64bit shift, 1i64 or Warning C4334
			j++;
		}
		i++;
		j = 0;
	}

	/*
	for (int i = 0; i < BOARD_HEIGHT; i++) {
		for (int j = 0; j < BOARD_WIDTH; j++) {
			if (Board[i][j] == Color)
				m_value += (1i64 << ( j* 8 + i) ); // Using 64bit shift, 1i64 or Warning C4334
		}
	}
	*/
	// It's hard to use range based for here, since there is no index in ranged based for
	// and the 2-dimensional array parameter no callalbe begin() and end()
	// int [][] is int* [], not a 2-D array
	// Using (&)[][]
	// or using std::vector
}

