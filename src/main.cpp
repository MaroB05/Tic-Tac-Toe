#include "Grid.h"

/*  We have a 3x3 int grid for the game (maybe we could modify it later)
 *  0 means the cell hasn't been used
 *  1 is set by player 1 (X)
 *  2 is set by player 2 (O) 
 *
 * Questions:
 * - How to handle invalid access? (Exceptions? or using return value as indicators?)
 *
 *  */


int main(){

  Grid grid = Grid();
  int player = 1;
  int r,c;
  int turn = 0;
  int winner = 0;
  while (turn < 9 && !winner){
    grid.render();
    
    do{ 
      cout << "player " << player << " row, column: ";
      cin >> r >> c;
    }while (!grid.set_cell(r, c, player));
    winner = grid.game_ended();

    if (player == 1){
      player = 2;
    } else {
      player = 1;
    }
    turn++;
  }

  if (winner){
    cout << "The winner is Player " << winner << endl;
  } else{
    cout << "We have a draw\n";
  }

  return 0;
}
