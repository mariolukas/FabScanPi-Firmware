#ifndef BOARDS_H
#define BOARDS_H

#define BOARD_UNKNOWN -1

#define BOARD_FABSCANPI             1    
#define BOARD_CYCLOP                2
#define BOARD_SANGUINOLOLU          3
#define BOARD_CNCSHIELD             4

#define MB(board) (MOTHERBOARD==BOARD_##board)

#endif
