void start();

void read_size(int *, int *);

int choose_difficulty(int, int);

void create_board(int ***, int ***, int, int);

void place_mines(int **, int, int, int);

void print_board(int **, int **, int, int);

void play(int **, int **, int, int, int);

int count_opened(int **, int, int);

int valid_coordinates(int, int, int, int);

int open(int **, int **, int, int, int, int);

void open_adjacent(int **, int **, int, int, int, int);

void mark(int **, int, int);

void cheat(int **, int, int);

int won(int **, int **, int, int);
