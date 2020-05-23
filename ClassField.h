#pragma once
struct Cells {
	bool isFilled;
	bool isEqualOne;
};

class Game_Field {
private:
	int Size_of_Field;
	Cells* cell;
public:
	Game_Field();
	bool set_cell_value(int x, int y, bool value);
	void print_field();
	void game_process();
	void move_of_player(int player_number);
	//void move_of_server();
	~Game_Field();
};