#include <iostream>
#include <string>
using namespace std;


class Grid{
private:
  int grid[3][3] = {0};
  char rendered_grid[3][7] = {' '};

public:

  Grid(){
    for (int i = 0; i < 3; i++){
      for (int j = 1; j < 5; j += 2){
        rendered_grid[i][j-1] = ' ';
        rendered_grid[i][j] = '|';
      }
      rendered_grid[i][6] = '\0';
    }
  }

  bool is_valid_cell(int r, int c){
    if (r > 2 || r < 0){
      cout << "Row out of range\n";
      return 0;
    }
    if (c > 2 || c < 0){
      cout << "Column out of range\n";
      return 0;
    }
    return 1;
  }

  int get_cell(int r, int c){ 
    if (is_valid_cell(r, c))
      return grid[r][c];
    return -1;
  }

  int set_cell(int r, int c, int value){
    if (!is_valid_cell(r, c))
      return 0;

    if (grid[r][c]){
      cout << "This cell is already used\n";
      return 0;
    }

    grid[r][c] = value;
    return 1;
  }


  int game_ended(){
    for (int i = 0; i < 3; i++){
      if (grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2]){
        return grid[i][0];
      }
    }

    for (int i = 0; i < 3; i++){
      if (grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i]){
        return grid[0][i];
      }
    }

    if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2]){
      return grid[0][0];
    }

    if (grid[2][0] == grid[1][1] && grid[1][1] == grid[0][2]){
      return grid[1][1];
    }

    return 0;
  }

  void print(){
    cout << "======================\n";
    for (int i = 0; i < 3; i++){
      for (int j = 0; j < 3; j++){
        cout << grid[i][j] << " ";
      }
      cout << "\n";
    }
  }

  void render(){
    cout << "======================\n";
    for (int i = 0; i < 3; i++){
      for (int j = 0; j < 3; j++){
        switch(grid[i][j]){
          case 1:
            rendered_grid[i][2 * j] = 'x';
            break;
          case 2:
            rendered_grid[i][2 * j] = 'o';
            break;
        }
      }
    }

    for (int i = 0; i < 3; i++)
      cout << rendered_grid[i] << "\n";
  }

};
