#include <iostream>
#include <string>
#include <time.h>
#include "ClassField.h"


using namespace std;
Game_Field::Game_Field() {
	srand(time(NULL));
	int RealSize;
	cout << "Enter size of squared field (NxN): ";
	cin >> Size_of_Field;
	RealSize = Size_of_Field * Size_of_Field;
	cell = new Cells[RealSize];
	for (int i = 0; i < RealSize; i++)
	{
		cell[i].isFilled = false;
		cell[i].isEqualOne = false;
	}

}

Game_Field::~Game_Field() {
	delete [] cell;
}

void Game_Field::print_field() {
	int RealSize = Size_of_Field * Size_of_Field;
	for (int i = 0; i < RealSize; i++)
	{
		cout << cell[i].isEqualOne << "\t";
		if ((i % Size_of_Field) == (Size_of_Field-1))
			cout << endl;
	}
}

bool Game_Field::set_cell_value(int x, int y, bool value) {
	int cell_position = (x - 1) * Size_of_Field + (y - 1);
	if (cell[cell_position].isFilled)
	{
		cout << "Cell is just filled. Choose another cell." << endl;
		return false;
	}
	else
	{
		cell[cell_position].isFilled = true;
		if(value)
			cell[cell_position].isEqualOne = true;
		return true;
	}
}

void Game_Field::game_process()
{
	int count_of_cells = Size_of_Field * Size_of_Field;
	for (int i = 0; i < count_of_cells; i++)
	{
		if (i % 2 == 0)
			move_of_player(1);
		else
		{
			move_of_player(2);
		}
	}
}

void Game_Field::move_of_player(int player_number)
{
	int coordinate_x, coordinate_y;
	bool record_is_successfull;
	do {
		cout << "Choose row: ";
		cin >> coordinate_x;
		if (coordinate_x <= 0 || coordinate_x > Size_of_Field)
		{
			system("cls");
			cout << "You exeeded maximum! Enter correct row!" << endl;
		}
	} while (coordinate_x <= 0 || coordinate_x > Size_of_Field);
	do {
		cout << "Choose column: ";
		cin >> coordinate_y;
		if (coordinate_y <= 0 || coordinate_y > Size_of_Field)
		{
			system("cls");
			cout << "You exeeded maximum! Enter correct column!" << endl;
		}
	} while (coordinate_y <= 0 || coordinate_y > Size_of_Field);
	if (player_number == 1)
		record_is_successfull = set_cell_value(coordinate_x, coordinate_y, true);
	else
		record_is_successfull = set_cell_value(coordinate_x, coordinate_y, false);
}
