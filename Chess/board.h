#ifndef BOARD_H
#define BOARD_H
#include "color.h"
#include <vector>
#include "pos.h"
#include "move.h"
#include "textdisplay.h"
#include "piece.h"

class Board {
    std::vector<std::vector <Piece*>> pieces; //all pieces on board
    std::vector <Move*> moves;
	TextDisplay* td = NULL;
	public:
	void insert (Pos pos, char letter);
	void remove (Pos pos);
	void updateTD(Pos oldpos, Pos newpos, char promo);
	std::vector<std::vector<Piece*>> getPieces();
    std::vector <Move*>* getMoves();
    bool outOfRange(const Pos p);
    bool isAttacked(Pos cellPos, std::vector< std::vector<Piece*> > pieces);
    void makeTheMove(Piece* moved, Piece* target);
    void notify(Pos pos, char promo);
	Board();
	~Board();
    friend std::ostream &operator<<(std::ostream &os, const Board &b);
};
#endif
