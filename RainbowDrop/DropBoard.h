#pragma once

enum DropColors { FIRE, WATER, WOOD, LIGHT, DARK, HEART };	// Ctrl-Shift-U -- To upper case, Ctrl-U To lower case

const static int BOARD_WIDTH = 6;
const static int BOARD_HEIGHT = 5;
const static int BOARD_SIZE = BOARD_WIDTH * BOARD_HEIGHT;

typedef unsigned __int64 BitBoardType;
class BitBoard {

	//	0 ---> 8,  0,0 is upper left, 
	// currently 6x5
	BitBoardType m_value;

public:
	BitBoardType getValue() { return m_value; }
	BitBoard(DropColors (&)[BOARD_HEIGHT][BOARD_WIDTH], DropColors);

};

//CryptGenRandom
// Intel rdrand instruction

class DropBoard {

public:
	enum DropSource { Screen, Picture };

	//Enumeration Type Naming Guidelines
	// https://msdn.microsoft.com/en-us/library/4x252001(v=vs.71).aspx
	// Pascal case

	DropBoard();	// Generate random drops
	DropBoard(DropSource);	// take drops from other source

private:
	BitBoard* m_fire;
	BitBoard* m_water;
	BitBoard* m_wood;
	BitBoard* m_light;
	BitBoard* m_dark;
	BitBoard* m_heart;
	DropColors m_board[BOARD_HEIGHT][BOARD_WIDTH];	
	/*	(0,0) (0,1) (0,2)
		(1,0) (1,3) ...
	*/

};
