#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "minesweeper.h"

/* Board limits */
#define MIN_SIZE 2
#define MAX_SIZE 20

/* Start the game */
void start() {
    int n, m, **board, **marked, mines;

    read_size(&n, &m); /* By reference */
    mines = choose_difficulty(n, m);
    create_board(&board, &marked, n, m);
    place_mines(board, n, m, mines);
    play(board, marked, n, m, mines);

    free(board);
    free(marked);
}

/* Read the board size */
void read_size(int *n, int *m) {
    printf("Enter the size of the board: ");
    /* Check if dimensions are in limits */
    while (1) {
        scanf("%d %d", n, m);
        if (*n < MIN_SIZE || *m < MIN_SIZE || *n > MAX_SIZE || *m > MAX_SIZE) {
            printf("Invalid size. Please, try again: ");
        } else {
            break;
        }
    }
}

/* Choose the difficulty */
/* Calculate and return the number of mines */
int choose_difficulty(int n, int m) {
    int choice;

    printf("\nChoose difficulty:\n");
    printf("1. Easy\n");
    printf("2. Medium\n");
    printf("3. Hard\n");
    printf("4. Impossible\n");
    printf("Enter your choice: ");

    /* Check if choice is in limits 1-4 */
    while (1) {
        scanf("%d", &choice);
        if (choice < 1 || choice > 4) {
            printf("Invalid choice. Pleae, try again: ");
        } else {
            break;
        }
    }

    switch (choice) {
    case 1:
        return n * m * 10 / 100;
    case 2:
        return n * m * 15 / 100;
    case 3:
        return n * m * 20 / 100;
    case 4:
        return n * m * 25 / 100;
    }
}

/* Create the board */
/* board & marked are pointers to 2-dimensional arrays */
void create_board(int ***board, int ***marked, int n, int m) {
    int i, j, r;

    *board = (int **) malloc(n * sizeof(int *));

    /* Check if there is enough memory */
    if (*board == NULL) {
        printf("Not enough memory!\n");
        exit(1);
    }

    *marked = (int **) malloc(n * sizeof(int *));

    /* Check if there is enough memory */
    if (*marked == NULL) {
        printf("Not enough memory!\n");
        exit(1);
    }

    /* Initialize random number generator */
    srand(time(NULL));

    /* Allocate memory for each row */
    for (i = 0; i < n; i++) {
        (*board)[i] = (int *) malloc(m * sizeof(int));
        (*marked)[i] = (int *) malloc(m * sizeof(int));
        /* Initialize each cell with 0 */
        for (j = 0; j < m; j++) {
            (*board)[i][j] = 0;
            (*marked)[i][j] = 0;
        }
    }
}

/* Calculate the number of adjacent mines */
int adjacent_mines(int **board, int x, int y, int n, int m) {
    int i, j, count = 0;

    /* Check all adjacent cells */
    for (i = x - 1; i <= x + 1; i++) {
        for (j = y - 1; j <= y + 1; j++) {
            /* Check if the cell is in the board and if it is a mine */
            if (i >= 0 && i < n && j >= 0 && j < m && board[i][j] == -1) {
                count++;
            }
        }
    }

    return count;
}

/* Place mines on the board */
void place_mines(int **board, int n, int m, int mines) {
    int i, j, r;

    srand(time(NULL));

    while (mines > 0) {
        r = rand() % (n * m); /* [0, n*m) */
        /* Convert r to 2-dimensional coordinates */
        i = r / m;
        j = r % m;
        /* Place a mine */
        /* -1 means mine in the board array */
        if (board[i][j] != -1) {
            board[i][j] = -1;
            mines--;
        }
    }

    /* For the rest of the cell */
    /* Calculate the number of adjacent mines */
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (board[i][j] != -1) {
                board[i][j] = adjacent_mines(board, i, j, n, m);
            }
        }
    }
}

void print_board(int **board, int **marked, int n, int m) {
    int i, j;

    printf("\n   ");
    for (j = 0; j < m; j++) {
        printf("%2d", j + 1);
    }
    printf("\n");

    printf(" --");
    for (j = 0; j < m; j++) {
        printf("--");
    }
    printf("\n");

    for (i = 0; i < n; i++) {
        printf("%2d|", i + 1);
        for (j = 0; j < m; j++) {
            /* The cell has been opened */
            if (marked[i][j] == 1) {
                /* The cell has a mine */
                if (board[i][j] == -1) {
                    printf(" @");
                    /* The cell has no adjacent mines */
                } else if (board[i][j] == 0) {
                    printf(" .");
                    /* The cell has that many adjacent mines */
                } else {
                    printf("%2d", board[i][j]);
                }
                /* The cell has been marked */
            } else if (marked[i][j] == 2) {
                printf(" @");
                /* The cell has not been opened */
                /* marked[i][j] == 0 */
            } else {
                printf(" #");
            }
        }
        printf("\n");
    }
}

void play(int **board, int **marked, int n, int m, int mines) {

    char line[100], command[100];
    int x, y, c, o;

    c = 0;
    while (1) {
        c++;

        print_board(board, marked, n, m);
        /* Calculate the number of opened cells */
        o = count_opened(marked, n, m);

        printf("\n");
        printf("%d block(s) are open.\n", o);
        printf("Make your move(s): ");

        scanf("%s", line);
        if (strcmp(line, "exit") == 0) { /* equals */
            break;
        } else {
            /* sscanf() reads formatted input from a string */
            /* %[^'('] means read until '(' */
            sscanf(line, "%[^'('](%d,%d)", command, &x, &y);
            if (strcmp(command, "open") == 0 || strcmp(command, "mark") == 0 || strcmp(command, "cheat") == 0) {
                /* Convert to 0-based coordinates */
                /* 1,1 -> 0,0 etc */
                x--;
                y--;

                /* Check if coordinates are valid */
                if (valid_coordinates(n, m, x, y) == 0) {
                    printf("Invalid coordinates\n");
                    continue;
                }

                if (strcmp(command, "open") == 0) {
                    int lost = open(board, marked, n, m, x, y);

                    if (lost) {
                        printf("You lost!\n");
                        break;
                    }

                    /* Check if the player won */
                    if (won(board, marked, n, m)) {
                        print_board(board, marked, n, m);
                        printf("You won!\n");
                        break;
                    }
                } else if (strcmp(command, "mark") == 0) {
                    mark(marked, x, y);
                } else if (strcmp(command, "cheat") == 0) {
                    cheat(board, x, y);
                }
            } else {
                printf("Invalid command\n");
            }
        }
    }
}

int count_opened(int **marked, int n, int m) {
    int i, j, count = 0;

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            /* The cell has been opened */
            if (marked[i][j] == 1) {
                count++;
            }
        }
    }

    return count;
}

int valid_coordinates(int n, int m, int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m) {
        return 0;
    } else {
        return 1;
    }
}

int open(int **board, int **marked, int n, int m, int x, int y) {
    while (1) {
        /* The cell has been opened */
        if (marked[x][y] == 1) {
            printf("This block is already open. Pease, try again\n");
            /* Read coordinates again */
            scanf("%d,%d", &x, &y);
        } else {
            break;
        }
    }

    /* The cell contains a mine */
    if (board[x][y] == -1) {
        marked[x][y] = 1;
        return 1; /* lost */
    } else {
        /* If the cell does not contain a mine */
        /* Open adjacent cells, when there are no adjacent mines */
        open_adjacent(board, marked, n, m, x, y);
        return 0; /* not lost */
    }
}

/* Recursive function that opens adjacent cells */
/* as long as there are no adjacent mines */
void open_adjacent(int **board, int **marked, int n, int m, int x, int y) {
    /* Cell is already open */
    if (marked[x][y] == 1) return;

    /*  Mark as open */
    marked[x][y] = 1;

    /* If there are adjacent mines, stop */
    if (board[x][y] != 0) return;

    /* Check all adjacent cells */
    /* in the x and y axis */
    if (valid_coordinates(n, m, x - 1, y)) open_adjacent(board, marked, n, m, x - 1, y);
    if (valid_coordinates(n, m, x, y - 1)) open_adjacent(board, marked, n, m, x, y - 1);
    if (valid_coordinates(n, m, x + 1, y)) open_adjacent(board, marked, n, m, x + 1, y);
    if (valid_coordinates(n, m, x, y + 1)) open_adjacent(board, marked, n, m, x, y + 1);
}

void mark(int **marked, int x, int y) {
    /* The cell has been opened */
    if (marked[x][y] == 1) {
        printf("This block is already open. Pease, try again\n");
        scanf("%d,%d", &x, &y);
        /* The cell has been marked */
    } else if (marked[x][y] == 2) {
        printf("This block is already marked. Pease, try again\n");
        scanf("%d,%d", &x, &y);
    }

    /* Mark the cell */
    marked[x][y] = 2;
}

void cheat(int **board, int x, int y) {
    /* The cell contains a mine */
    if (board[x][y] == -1) {
        printf("This block is a mine. Be careful!\n");
    } else {
        printf("This block has %d adjacent mine(s).\n", board[x][y]);
    }
}

int won(int **board, int **marked, int n, int m) {
    int i, j, count;

    /* Count the number of cells that have not been opened */
    /* and do not contain a mine */
    count = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (board[i][j] > -1 && marked[i][j] == 0) {
                count++;
            }
        }
    }

    if (count == 0) {
        return 1; /* won */
    } else {
        return 0; /* not won */
    }
}
