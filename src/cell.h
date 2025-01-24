/*
Labirinto para Computacao Grafica (CG).
(C) 2010 Pedro Freire (www.pedrofreire.com)
    Licenca Creative Commons:
    Atribuicao - Uso Nao-Comercial - Partilha nos termos da mesma Licenca
    http://creativecommons.org/licenses/by-nc-sa/2.5/pt/

Computer Graphics Maze.
(C) 2010 Pedro Freire (www.pedrofreire.com)
    All comments in Portuguese.
    Creative Commons license:
    Attribution - Noncommercial - Share Alike
    http://creativecommons.org/licenses/by-nc-sa/2.5/pt/deed.en_US
*/


#ifndef CELL_H
#define CELL_H

// **** Ficheiro independente para evitar referencia circular
// **** entre map.h e student_mapdraw.h


/* Estrutura que define os valores nas celulas do mapa do labirinto.
   "type" apenas pode conter os valores defenidos na enumeracao.
   "object" e' para descrever um objecto nessa localizacao, definido pelo
   programador, e pode ser ajustado apos criacao do labirinto com
   setCellObject().
   "players" descreve quais os jogadores que ja' visitaram esta celula.
   E' um mapa de 32 bits, 1 bit por jogador. O bit 0 refere-se ao primeiro
   jogador, o bit 1 ao segundo, etc.. Pode ser ajustado apos criacao do
   labirinto com setCellPlayer().
   NOTA IMPORTANTE: Apesar das facilidades existentes nesta classe, neste
   momento o labirinto e' usado apenas com:
	FLOOR, WALL, sem  objectos e apenas usando um jogador (1U).
*/
struct Cell
{
    enum Type { FLOOR = 0x0,  DOOR_OPEN   = 0x1,
		WALL  = 0x2,  DOOR_CLOSED = 0x3 } type;
    int object;
    unsigned int players;

    Cell( Type t = FLOOR, int obj = 0 )
	{ this->type = t; this->object = obj; this->players = 0U; }
    bool isWall()          { return this->type == WALL; }
    bool isWallOrClosed()  { return  (bool) ((int)this->type & 0x2); }
    bool isWallOrDoor()    { return this->type != FLOOR; }
    bool isFloor()         { return this->type == FLOOR; }
    bool isFloorOrOpen()   { return !(bool) ((int)this->type & 0x2); }
    bool isFloorOrDoor()   { return this->type != WALL; }
    bool isDoor()          { return  (bool) ((int)this->type & 0x1); }
};


#endif // CELL_H
