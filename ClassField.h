#pragma once
struct Cells {
	bool isFilled;
	int value;
};

class Game_Field {
private:
	Game_Field* p_instance;
	int Size_of_Field;
	Cells* cell;
	bool second_player_is_server;
	Game_Field();
	Game_Field(const Game_Field&);
	Game_Field& operator=(Game_Field&);
public:
	static Game_Field* getInstance();
	void change_size_of_field(int new_size);
	bool set_cell_value(int x, int y, int value);
	void game_process(int size);
	void move_of_player(int player_number);
	void move_of_server();
	void set_opponent(bool opponent_type);
	bool opponent_is_server();
	int choose_coordinate(int coord);
	void count_even_summs();
	int count_rows();
	int count_columns();
	int count_diags();
	bool is_filled();
	~Game_Field();
};