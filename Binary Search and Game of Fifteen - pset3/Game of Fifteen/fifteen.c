/***************************************************************************
 * fifteen.c
 *
 * Emin Israfil
 * Computer Science 50
 * Problem Set 3
 *
 * Implements The Game of Fifteen (generalized to d x d).
 * Goal: Arrange number tiles in ascending order, moving only 1 tile at a time
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 ***************************************************************************/
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


// constants
#define DIM_MIN 3
#define DIM_MAX 9
#define BLANK 99


// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;

int blanki;
int blankj;


// prototypes
void clear(void);
void greet(void);
void init(int);
void draw(void);
bool move(int tile);
bool won(void);
void swap(int, int, int);


int
main(int argc, char *argv[])
{
    // greet user with instructions
    greet();

    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %d x %d and %d x %d, inclusive.\n",
         DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // initialize the board
    init(d);
    
    

    
    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = GetInt();

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
           //usleep(500000);
        }

        // sleep thread for animation's sake
        //usleep(500000);
    }

    // that's all folks
    return 0;
}


/*
 * Clears screen using ANSI escape sequences.
 */

void
clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}


/*
 * Greets player.
 */

void
greet(void)
{
    clear();
    printf("WELCOME TO THE GAME OF FIFTEEN\n");
    usleep(2000000);
}


/*
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 */

void
init(int d)
{
//int board[d-1][d-1];
    for(int i = 0, j= 0, k = d*d-1; i<d; i++, j++)
      {
      
      for(int j= 0; j<d; j++, k--)
        {
        board[i][j] = k;  
        //printf("%d  ", board[i][j]);
        }
        
        printf("\n");
   
      }
   board[d-1][d-1] =  BLANK;
   blanki = d-1;
   blankj = d-1;
//   printf("%d%d  ", blankj, blanki);
  
   if(!((d*d) % 2 > 0))
    {
    board[d-1][d-2]= 2;
    board[d-1][d-3]= 1;
    }

}


/* 
 * Prints the board in its current state.
 */

void
draw(void)
{
    for(int i = 0, j= 0; i<d; i++, j++)
      {
      printf("\n\n    ");
      for(int j= 0; j<d; j++)
        { 
        
        printf("%2d  ", board[i][j]);
        //if (board[i][j] == 0)
            //printf("\b\b* ");
        }     
      }
    printf("\n    ");
}


/* 
 * If tile borders empty space, moves tile and returnsls true, else
 * returns false. 
 */

bool
move(int tile)
{
    for(int i = 0, j= 0; i<d; i++, j++)
      {
      for(int j= 0; j<d; j++)
        { 
            if(tile == board[i][j])
                {
                printf("Found it! %d%d ", j,i );
                if(((i+1)== blanki) && ((j)== blankj))
                    {
                    printf("the tile is above! %d%d ", i, blanki );
                    swap(j, i, tile);
                    return true;
                    }
                if(((i-1)== blanki) && ((j)== blankj))
                    {
                    printf("the tile is below! %d%d ", i, blanki );
                    swap(j, i, tile);
                    return true;
                    }
                if(((i)== blanki) && ((j-1)== blankj))
                    {
                    printf("the tile is to the right! %d%d ", j, blanki );
                    swap(j, i, tile);
                    return true;
                    }
                if(((i)== blanki) && ((j+1)== blankj))
                    {
                    printf("the tile is to the left! %d%d ", j, blanki );
                    swap(j, i, tile);
                    return true;
                    }
                }
        }
        
        
      }
    
    return false;
}


/*
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */
void swap(int j, int i, int tile) 
{
//int swapster[0][0];
//swapster[0][0] = board[j][i];


board[blanki][blankj] = tile;
//printf("board[blankj][blanki]: %d \n", board[blankj][blanki]);
blankj = j;
blanki = i;
board[blanki][blankj] = BLANK;

//printf("board[blankj][blanki]: %d \n", board[blankj][blanki]);

} 

bool
won(void)
{
int k = 0;
      for(int i = 0, j= 0; i<d; i++, j++)
      {
            for(int j= 0; j<d-1; j++)
              { 
                  if(board[i][j] > board[i][j+1])
                  k++;
                  if ((j== d-2))
                        if(i < d -1) 
                        if(board[i][j+1] > board[i-1][j])
                            k++;
              }
                   
      }
    if(k > 0)   
        return false;
    else return true;
}
