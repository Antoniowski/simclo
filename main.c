#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>

const char* block = "\u2588";
const int LINE_DIM = 3;
const int NUM_CELL_WIDTH = 9;
const int NUM_CELL_HEIGHT = 5;
const int INTER_NUM_DIST = 2;

static int CENTER_X = 0;
static int CENTER_Y = 0;
static unsigned short int blink_sec = 0;

struct number_dim{
    int width; 
    int height;
};

void second_blink(void)
{
    if (blink_sec)
    {
        blink_sec = 0;
    }
    else
    {
        blink_sec = 1;
    }
}

void start_row(int current_col, int number_pos)
{
    if (current_col == 0)
    {
        printf("\033[%dA", (NUM_CELL_HEIGHT/2)); // Move up X lines;cle
    }
    printf("\033[%dD", (5 * NUM_CELL_WIDTH + 4 * INTER_NUM_DIST) / 2); // Move left X column;
    if (number_pos > 0)
    {
        printf("\033[%dC", (number_pos * (NUM_CELL_WIDTH + INTER_NUM_DIST))); // Move right X column;
    }
    
}

void end_row(int current_row, int number_pos)
{
    if (current_row == NUM_CELL_WIDTH - 1)
    {
        printf("\n");
        //Move the cursor again in the center
        printf("\033[%dC", CENTER_X); // Move right X column;
    }
}

struct number_dim print_number(int number_to_print, int position){
    struct number_dim num_d = { .width = 0, .height = 0};
    switch (number_to_print)
    {
    case 0:
        for (size_t i = 0; i < NUM_CELL_HEIGHT; i++)
        {
            start_row(i, position);
            for (size_t x = 0; x < NUM_CELL_WIDTH; x++)
            {
                // FIRST AND LAST ROW
                if (i == 0 || i == NUM_CELL_HEIGHT - 1)
                {
                    printf("%s", block);
                }
                else
                {
                    if (x < 3 || x > 5)
                    {
                        printf("%s", block);
                    }
                    else
                    {
                        printf(" ");
                    }
                }
                end_row(x, position);
            }           
        }       
        num_d.height = 5;
        num_d.width = 9;
        break;

    case 1:
        num_d.width = 3;
        num_d.height = 5;
        for (size_t i = 0; i < NUM_CELL_HEIGHT; i++) // height
        {  
            start_row(i, position);
            for (size_t x = 0; x < NUM_CELL_WIDTH; x++) // width
            {   
                if (x <= NUM_CELL_WIDTH - (LINE_DIM + 1))
                {
                    printf(" ");
                }
                else
                {
                    printf("%s", block);
                    end_row(x, position);   
                }
            }
        }        
        break;

    case 2:
        for (size_t i = 0; i < NUM_CELL_HEIGHT; i++)
        {
            start_row(i, position);
            for (size_t x = 0; x < NUM_CELL_WIDTH; x++)
            {
                if (i == 0 || i == 2 || i == 4)
                {
                    printf("%s", block);
                }
                else if (i == 1)
                {
                    if (x > NUM_CELL_WIDTH - 4)
                    {
                        printf("%s", block);
                    }
                    else
                    {
                        printf(" ");
                    }
                }
                else
                {
                    if (x < 3)
                    {
                        printf("%s", block);
                    }
                    else
                    {
                        printf(" ");
                    }
                }
                end_row(x, position);
            }
        }
        break;
        
    case 3:
        for (size_t i = 0; i < NUM_CELL_HEIGHT; i++)
        {
            start_row(i, position);
            for (size_t x = 0; x < NUM_CELL_WIDTH; x++)
            {
                if (i == 0 || i == 2 || i == 4)
                {
                    printf("%s", block);
                }
                else
                {
                    if (x > NUM_CELL_WIDTH - 4)
                    {
                        printf("%s", block);
                    }
                    else
                    {
                        printf(" ");
                    }
                }

                end_row(x, position);
            }
            
        }
        break;

    case 4:
        for (size_t i = 0; i < NUM_CELL_HEIGHT; i++)
        {
            start_row(i, position);
            for (size_t x = 0; x < NUM_CELL_WIDTH; x++)
            {
                if (i < 2)
                {
                    if (x < 3 || x > 5)
                    {
                        printf("%s", block);
                    }
                    else
                    {
                        printf(" ");
                    }
                }
                else if (i == 2)
                {
                    printf("%s", block);
                }
                else
                {
                    if (x < NUM_CELL_WIDTH - 3)
                    {
                        printf(" ");
                    }
                    else
                    {
                        printf("%s", block);
                    }

                }
                
                end_row(x, position);
            }
        }
        break;
        
    case 5:
        for (size_t i = 0; i < NUM_CELL_HEIGHT; i++)
        {
            start_row(i, position);
            for (size_t x = 0; x < NUM_CELL_WIDTH; x++)
            {
                
                if (i == 0 || i == 2 || i == 4)
                {
                    printf("%s", block);
                }
                else if (i == 1)
                {
                    if (x < 3)
                    {
                        printf("%s", block);
                    }
                    else
                    {
                        printf(" ");
                    }
                }
                else
                {
                    if (x > NUM_CELL_WIDTH - 4)
                    {
                        printf("%s", block);
                    }
                    else
                    {
                        printf(" ");
                    }
                }
                
                end_row(x, position);
            }
            
        }
        break;
    case 6:
        for (size_t i = 0; i < NUM_CELL_HEIGHT; i++)
        {
            start_row(i, position);
            for (size_t x = 0; x < NUM_CELL_WIDTH; x++)
            {
                if (i == 0 || i == 2 || i == 4)
                {
                    printf("%s", block);
                }
                else if (i == 1)
                {
                    if (x < 3)
                    {
                        printf("%s", block);
                    }
                    else
                    {
                        printf(" ");
                    }
                }
                else
                {
                    if (x > NUM_CELL_WIDTH - 4 || x < 3)
                    {
                        printf("%s", block);
                    }
                    else
                    {
                        printf(" ");
                    }
                }
                
                end_row(x, position);
            }
        }
        break;
        
    case 7:
        for (size_t i = 0; i < NUM_CELL_HEIGHT; i++) // height
        {  
            start_row(i, position);
            for (size_t x = 0; x < NUM_CELL_WIDTH; x++) // width
            {   
                if (i == 0)
                {
                    printf("%s", block);
                }
                else
                {
                    if (x <= NUM_CELL_WIDTH - (LINE_DIM + 1))
                    {
                        printf(" ");
                    }
                    else
                    {
                        printf("%s", block); 
                    }
    
                }
                
                end_row(x, position);  
            }
        }
        break;
    case 8:
        for (size_t i = 0; i < NUM_CELL_HEIGHT; i++)
        {
            start_row(i, position);
            for (size_t x = 0; x < NUM_CELL_WIDTH; x++)
            {
                if (i == 0 || i == 2 || i == 4)
                {
                    printf("%s", block);
                }
                else
                {
                    if (x < 3 || x > NUM_CELL_WIDTH - 4)
                    {
                        printf("%s", block);
                    }
                    else
                    {
                        printf(" ");
                    }
                }
    
                end_row(x, position);
            }
        }
        break;
    case 9:
        for (size_t i = 0; i < NUM_CELL_HEIGHT; i++)
        {
            start_row(i, position);

            for (size_t x = 0; x < NUM_CELL_WIDTH; x++)
            {
                if (i == 0 || i == 2)
                {
                    printf("%s", block);
                }
                else if (i == 1)            
                {
                    if (x < 3 || x > NUM_CELL_WIDTH - 4)
                    {
                        printf("%s", block);
                    }
                    else
                    {
                        printf(" ");
                    }
                }
                else
                {
                    if (x <= NUM_CELL_WIDTH - (LINE_DIM + 1))
                    {
                        printf(" ");
                    }
                    else
                    {
                        printf("%s", block); 
                    }
                }

                end_row(x, position);
            }
        }
        break;
    default:
        for (size_t i = 0; i < NUM_CELL_HEIGHT; i++)
        {
            start_row(i, position);
            for (size_t x = 0; x < NUM_CELL_WIDTH; x++)
            {
                if (i == 1 || i == 3)
                {
                    if (x > 2 && x < 6 && blink_sec)
                    {
                        printf("%s", block);
                    }
                    else
                    {
                        printf(" ");  
                    }
                }
                else
                {
                    printf(" ");
                }
                end_row(x, position);
            }
        }
        break;
    }
    return num_d;
}


void print_hours(struct tm *t)
{
    //Move cursor in the center
    printf("\033[%dB", CENTER_Y); // Move down X column;
    printf("\033[%dC", CENTER_X); // Move right X column;
    
    if (t->tm_hour < 10)
    {
        print_number(0, 0);
        //Move cursor in the center
        printf("\e[H");  //Reset cursor to the origin
        printf("\033[%dB", CENTER_Y); // Move down X column;
        printf("\033[%dC", CENTER_X); // Move right X column;
        print_number(t->tm_hour, 1);
        printf("\e[H");  //Reset cursor to the origin
        printf("\033[%dB", CENTER_Y); // Move down X column;
        printf("\033[%dC", CENTER_X); // Move right X column;        
    }
    else if (t->tm_hour >= 10 && t->tm_hour < 20)
    {
        print_number(1, 0);
        //Move cursor in the center
        printf("\e[H");  //Reset cursor to the origin
        printf("\033[%dB", CENTER_Y); // Move down X column;
        printf("\033[%dC", CENTER_X); // Move right X column;
        switch (t->tm_hour)
        {
        case 10:
            print_number(0, 1);
            //Move cursor in the center
            printf("\e[H");  //Reset cursor to the origin
            printf("\033[%dB", CENTER_Y); // Move down X column;
            printf("\033[%dC", CENTER_X); // Move right X column;
            break;
        case 11:
            print_number(1, 1);
            //Move cursor in the center
            printf("\e[H");  //Reset cursor to the origin
            printf("\033[%dB", CENTER_Y); // Move down X column;
            printf("\033[%dC", CENTER_X); // Move right X column;
            break;
        case 12:
            print_number(2, 1);
            //Move cursor in the center
            printf("\e[H");  //Reset cursor to the origin
            printf("\033[%dB", CENTER_Y); // Move down X column;
            printf("\033[%dC", CENTER_X); // Move right X column;
            break;
        case 13:
            print_number(3, 1);
            //Move cursor in the center
            printf("\e[H");  //Reset cursor to the origin
            printf("\033[%dB", CENTER_Y); // Move down X column;
            printf("\033[%dC", CENTER_X); // Move right X column;
            break;
        case 14:
            print_number(4, 1);
            //Move cursor in the center
            printf("\e[H");  //Reset cursor to the origin
            printf("\033[%dB", CENTER_Y); // Move down X column;
            printf("\033[%dC", CENTER_X); // Move right X column;
            break;
        case 15:
            print_number(5, 1);
            //Move cursor in the center
            printf("\e[H");  //Reset cursor to the origin
            printf("\033[%dB", CENTER_Y); // Move down X column;
            printf("\033[%dC", CENTER_X); // Move right X column;
            break;
        case 16:
            print_number(6, 1);
            //Move cursor in the center
            printf("\e[H");  //Reset cursor to the origin
            printf("\033[%dB", CENTER_Y); // Move down X column;
            printf("\033[%dC", CENTER_X); // Move right X column;
            break;
        case 17:
            print_number(7, 1);
            //Move cursor in the center
            printf("\e[H");  //Reset cursor to the origin
            printf("\033[%dB", CENTER_Y); // Move down X column;
            printf("\033[%dC", CENTER_X); // Move right X column;
            break;
        case 18:
            print_number(8, 1);
            //Move cursor in the center
            printf("\e[H");  //Reset cursor to the origin
            printf("\033[%dB", CENTER_Y); // Move down X column;
            printf("\033[%dC", CENTER_X); // Move right X column;
            break;
        case 19:
            print_number(9, 1);
            //Move cursor in the center
            printf("\e[H");  //Reset cursor to the origin
            printf("\033[%dB", CENTER_Y); // Move down X column;
            printf("\033[%dC", CENTER_X); // Move right X column;
            break;
        
        default:
            break;
        }
    }
    else
    {
        print_number(2, 0);
        //Move cursor in the center
        printf("\e[H");  //Reset cursor to the origin
        printf("\033[%dB", CENTER_Y); // Move down X column;
        printf("\033[%dC", CENTER_X); // Move right X column;
        switch (t->tm_hour)
        {
        case 20:
            print_number(0, 1);
            //Move cursor in the center
            printf("\e[H");  //Reset cursor to the origin
            printf("\033[%dB", CENTER_Y); // Move down X column;
            printf("\033[%dC", CENTER_X); // Move right X column;
            break;
        case 21:
            print_number(1, 1);
            //Move cursor in the center
            printf("\e[H");  //Reset cursor to the origin
            printf("\033[%dB", CENTER_Y); // Move down X column;
            printf("\033[%dC", CENTER_X); // Move right X column;
            break;
        case 22:
            print_number(2, 1);
            //Move cursor in the center
            printf("\e[H");  //Reset cursor to the origin
            printf("\033[%dB", CENTER_Y); // Move down X column;
            printf("\033[%dC", CENTER_X); // Move right X column;
            break;
        case 23:
            print_number(3, 1);
            //Move cursor in the center
            printf("\e[H");  //Reset cursor to the origin
            printf("\033[%dB", CENTER_Y); // Move down X column;
            printf("\033[%dC", CENTER_X); // Move right X column;
            break;
        default:
            break;
        }
    }
}

void print_minutes(struct tm *t)
{
    if (t->tm_min < 10)
    {
        print_number(0, 3);
        //Move cursor in the center
        printf("\e[H");  //Reset cursor to the origin
        printf("\033[%dB", CENTER_Y); // Move down X column;
        printf("\033[%dC", CENTER_X); // Move right X column;
        print_number(t->tm_min, 4);
        printf("\e[H");  //Reset cursor to the origin
        printf("\033[%dB", CENTER_Y); // Move down X column;
        printf("\033[%dC", CENTER_X); // Move right X column;   
    }
    else if (t->tm_min >= 10 && t->tm_min < 20)
    {
        print_number(1, 3);
        //Move cursor in the center
        printf("\e[H");  //Reset cursor to the origin
        printf("\033[%dB", CENTER_Y); // Move down X column;
        printf("\033[%dC", CENTER_X); // Move right X column;
        switch (t->tm_min)
        {
        case 10:
            print_number(0, 4);
            //Move cursor in the center
            printf("\e[H");  //Reset cursor to the origin
            printf("\033[%dB", CENTER_Y); // Move down X column;
            printf("\033[%dC", CENTER_X); // Move right X column;
            break;
        case 11:
            print_number(1, 4);
            //Move cursor in the center
            printf("\e[H");  //Reset cursor to the origin
            printf("\033[%dB", CENTER_Y); // Move down X column;
            printf("\033[%dC", CENTER_X); // Move right X column;
            break;
        case 12:
            print_number(2, 4);
            //Move cursor in the center
            printf("\e[H");  //Reset cursor to the origin
            printf("\033[%dB", CENTER_Y); // Move down X column;
            printf("\033[%dC", CENTER_X); // Move right X column;
            break;
        case 13:
            print_number(3, 4);
            //Move cursor in the center
            printf("\e[H");  //Reset cursor to the origin
            printf("\033[%dB", CENTER_Y); // Move down X column;
            printf("\033[%dC", CENTER_X); // Move right X column;
            break;
        case 14:
            print_number(4, 4);
            //Move cursor in the center
            printf("\e[H");  //Reset cursor to the origin
            printf("\033[%dB", CENTER_Y); // Move down X column;
            printf("\033[%dC", CENTER_X); // Move right X column;
            break;
        case 15:
            print_number(5, 4);
            //Move cursor in the center
            printf("\e[H");  //Reset cursor to the origin
            printf("\033[%dB", CENTER_Y); // Move down X column;
            printf("\033[%dC", CENTER_X); // Move right X column;
            break;
        case 16:
            print_number(6, 4);
            //Move cursor in the center
            printf("\e[H");  //Reset cursor to the origin
            printf("\033[%dB", CENTER_Y); // Move down X column;
            printf("\033[%dC", CENTER_X); // Move right X column;
            break;
        case 17:
            print_number(7, 4);
            //Move cursor in the center
            printf("\e[H");  //Reset cursor to the origin
            printf("\033[%dB", CENTER_Y); // Move down X column;
            printf("\033[%dC", CENTER_X); // Move right X column;
            break;
        case 18:
            print_number(8, 4);
            //Move cursor in the center
            printf("\e[H");  //Reset cursor to the origin
            printf("\033[%dB", CENTER_Y); // Move down X column;
            printf("\033[%dC", CENTER_X); // Move right X column;
            break;
        case 19:
            print_number(9, 4);
            //Move cursor in the center
            printf("\e[H");  //Reset cursor to the origin
            printf("\033[%dB", CENTER_Y); // Move down X column;
            printf("\033[%dC", CENTER_X); // Move right X column;
            break;
        default:
            break;
        }
    }
    else if (t->tm_min >= 20 && t->tm_min < 30)
    {
        print_number(2, 3);
        //Move cursor in the center
        printf("\e[H");  //Reset cursor to the origin
        printf("\033[%dB", CENTER_Y); // Move down X column;
        printf("\033[%dC", CENTER_X); // Move right X column;
        switch (t->tm_min)
        {
        case 20:
            print_number(0, 4);
            //Move cursor in the center
            printf("\e[H");  //Reset cursor to the origin
            printf("\033[%dB", CENTER_Y); // Move down X column;
            printf("\033[%dC", CENTER_X); // Move right X column;
            break;
        case 21:
            print_number(1, 4);
            //Move cursor in the center
            printf("\e[H");  //Reset cursor to the origin
            printf("\033[%dB", CENTER_Y); // Move down X column;
            printf("\033[%dC", CENTER_X); // Move right X column;
            break;
        case 22:
            print_number(2, 4);
            //Move cursor in the center
            printf("\e[H");  //Reset cursor to the origin
            printf("\033[%dB", CENTER_Y); // Move down X column;
            printf("\033[%dC", CENTER_X); // Move right X column;
            break;
        case 23:
            print_number(3, 4);
            //Move cursor in the center
            printf("\e[H");  //Reset cursor to the origin
            printf("\033[%dB", CENTER_Y); // Move down X column;
            printf("\033[%dC", CENTER_X); // Move right X column;
            break;
        case 24:
            print_number(4, 4);
            //Move cursor in the center
            printf("\e[H");  //Reset cursor to the origin
            printf("\033[%dB", CENTER_Y); // Move down X column;
            printf("\033[%dC", CENTER_X); // Move right X column;
            break;
        case 25:
            print_number(5, 4);
            //Move cursor in the center
            printf("\e[H");  //Reset cursor to the origin
            printf("\033[%dB", CENTER_Y); // Move down X column;
            printf("\033[%dC", CENTER_X); // Move right X column;
            break;
        case 26:
            print_number(6, 4);
            //Move cursor in the center
            printf("\e[H");  //Reset cursor to the origin
            printf("\033[%dB", CENTER_Y); // Move down X column;
            printf("\033[%dC", CENTER_X); // Move right X column;
            break;
        case 27:
            print_number(7, 4);
            //Move cursor in the center
            printf("\e[H");  //Reset cursor to the origin
            printf("\033[%dB", CENTER_Y); // Move down X column;
            printf("\033[%dC", CENTER_X); // Move right X column;
            break;
        case 28:
            print_number(8, 4);
            //Move cursor in the center
            printf("\e[H");  //Reset cursor to the origin
            printf("\033[%dB", CENTER_Y); // Move down X column;
            printf("\033[%dC", CENTER_X); // Move right X column;
            break;
        case 29:
            print_number(9, 4);
            //Move cursor in the center
            printf("\e[H");  //Reset cursor to the origin
            printf("\033[%dB", CENTER_Y); // Move down X column;
            printf("\033[%dC", CENTER_X); // Move right X column;
            break;
        default:
            break;
        }
    }
    else if (t->tm_min >= 30 && t->tm_min < 40)
    {
        print_number(3, 3);
        //Move cursor in the center
        printf("\e[H");  //Reset cursor to the origin
        printf("\033[%dB", CENTER_Y); // Move down X column;
        printf("\033[%dC", CENTER_X); // Move right X column;
        switch (t->tm_min)
        {
        case 30:
            print_number(0, 4);
            //Move cursor in the center
            printf("\e[H");  //Reset cursor to the origin
            printf("\033[%dB", CENTER_Y); // Move down X column;
            printf("\033[%dC", CENTER_X); // Move right X column;
            break;
        case 31:
            print_number(1, 4);
            //Move cursor in the center
            printf("\e[H");  //Reset cursor to the origin
            printf("\033[%dB", CENTER_Y); // Move down X column;
            printf("\033[%dC", CENTER_X); // Move right X column;
            break;
        case 32:
            print_number(2, 4);
            //Move cursor in the center
            printf("\e[H");  //Reset cursor to the origin
            printf("\033[%dB", CENTER_Y); // Move down X column;
            printf("\033[%dC", CENTER_X); // Move right X column;
            break;
        case 33:
            print_number(3, 4);
            //Move cursor in the center
            printf("\e[H");  //Reset cursor to the origin
            printf("\033[%dB", CENTER_Y); // Move down X column;
            printf("\033[%dC", CENTER_X); // Move right X column;
            break;
        case 34:
            print_number(4, 4);
            //Move cursor in the center
            printf("\e[H");  //Reset cursor to the origin
            printf("\033[%dB", CENTER_Y); // Move down X column;
            printf("\033[%dC", CENTER_X); // Move right X column;
            break;
        case 35:
            print_number(5, 4);
            //Move cursor in the center
            printf("\e[H");  //Reset cursor to the origin
            printf("\033[%dB", CENTER_Y); // Move down X column;
            printf("\033[%dC", CENTER_X); // Move right X column;
            break;
        case 36:
            print_number(6, 4);
            //Move cursor in the center
            printf("\e[H");  //Reset cursor to the origin
            printf("\033[%dB", CENTER_Y); // Move down X column;
            printf("\033[%dC", CENTER_X); // Move right X column;
            break;
        case 37:
            print_number(7, 4);
            //Move cursor in the center
            printf("\e[H");  //Reset cursor to the origin
            printf("\033[%dB", CENTER_Y); // Move down X column;
            printf("\033[%dC", CENTER_X); // Move right X column;
            break;
        case 38:
            print_number(8, 4);
            //Move cursor in the center
            printf("\e[H");  //Reset cursor to the origin
            printf("\033[%dB", CENTER_Y); // Move down X column;
            printf("\033[%dC", CENTER_X); // Move right X column;
            break;
        case 39:
            print_number(9, 4);
            //Move cursor in the center
            printf("\e[H");  //Reset cursor to the origin
            printf("\033[%dB", CENTER_Y); // Move down X column;
            printf("\033[%dC", CENTER_X); // Move right X column;
            break;
        default:
            break;
        }
    }
    else if (t->tm_min >= 40 && t->tm_min < 50)
    {
        print_number(4, 3);
        //Move cursor in the center
        printf("\e[H");  //Reset cursor to the origin
        printf("\033[%dB", CENTER_Y); // Move down X column;
        printf("\033[%dC", CENTER_X); // Move right X column;
        switch (t->tm_min)
        {
        case 40:
            print_number(0, 4);
            //Move cursor in the center
            printf("\e[H");  //Reset cursor to the origin
            printf("\033[%dB", CENTER_Y); // Move down X column;
            printf("\033[%dC", CENTER_X); // Move right X column;
            break;
        case 41:
            print_number(1, 4);
            //Move cursor in the center
            printf("\e[H");  //Reset cursor to the origin
            printf("\033[%dB", CENTER_Y); // Move down X column;
            printf("\033[%dC", CENTER_X); // Move right X column;
            break;
        case 42:
            print_number(2, 4);
            //Move cursor in the center
            printf("\e[H");  //Reset cursor to the origin
            printf("\033[%dB", CENTER_Y); // Move down X column;
            printf("\033[%dC", CENTER_X); // Move right X column;
            break;
        case 43:
            print_number(3, 4);
            //Move cursor in the center
            printf("\e[H");  //Reset cursor to the origin
            printf("\033[%dB", CENTER_Y); // Move down X column;
            printf("\033[%dC", CENTER_X); // Move right X column;
            break;
        case 44:
            print_number(4, 4);
            //Move cursor in the center
            printf("\e[H");  //Reset cursor to the origin
            printf("\033[%dB", CENTER_Y); // Move down X column;
            printf("\033[%dC", CENTER_X); // Move right X column;
            break;
        case 45:
            print_number(5, 4);
            //Move cursor in the center
            printf("\e[H");  //Reset cursor to the origin
            printf("\033[%dB", CENTER_Y); // Move down X column;
            printf("\033[%dC", CENTER_X); // Move right X column;
            break;
        case 46:
            print_number(6, 4);
            //Move cursor in the center
            printf("\e[H");  //Reset cursor to the origin
            printf("\033[%dB", CENTER_Y); // Move down X column;
            printf("\033[%dC", CENTER_X); // Move right X column;
            break;
        case 47:
            print_number(7, 4);
            //Move cursor in the center
            printf("\e[H");  //Reset cursor to the origin
            printf("\033[%dB", CENTER_Y); // Move down X column;
            printf("\033[%dC", CENTER_X); // Move right X column;
            break;
        case 48:
            print_number(8, 4);
            //Move cursor in the center
            printf("\e[H");  //Reset cursor to the origin
            printf("\033[%dB", CENTER_Y); // Move down X column;
            printf("\033[%dC", CENTER_X); // Move right X column;
            break;
        case 49:
            print_number(9, 4);
            //Move cursor in the center
            printf("\e[H");  //Reset cursor to the origin
            printf("\033[%dB", CENTER_Y); // Move down X column;
            printf("\033[%dC", CENTER_X); // Move right X column;
            break;
        default:
            break;
        }
    }
    else
    {
        print_number(5, 3);
        //Move cursor in the center
        printf("\e[H");  //Reset cursor to the origin
        printf("\033[%dB", CENTER_Y); // Move down X column;
        printf("\033[%dC", CENTER_X); // Move right X column;
        switch (t->tm_min)
        {
        case 50:
            print_number(0, 4);
            //Move cursor in the center
            printf("\e[H");  //Reset cursor to the origin
            printf("\033[%dB", CENTER_Y); // Move down X column;
            printf("\033[%dC", CENTER_X); // Move right X column;
            break;
        case 51:
            print_number(1, 4);
            //Move cursor in the center
            printf("\e[H");  //Reset cursor to the origin
            printf("\033[%dB", CENTER_Y); // Move down X column;
            printf("\033[%dC", CENTER_X); // Move right X column;
            break;
        case 52:
            print_number(2, 4);
            //Move cursor in the center
            printf("\e[H");  //Reset cursor to the origin
            printf("\033[%dB", CENTER_Y); // Move down X column;
            printf("\033[%dC", CENTER_X); // Move right X column;
            break;
        case 53:
            print_number(3, 4);
            //Move cursor in the center
            printf("\e[H");  //Reset cursor to the origin
            printf("\033[%dB", CENTER_Y); // Move down X column;
            printf("\033[%dC", CENTER_X); // Move right X column;
            break;
        case 54:
            print_number(4, 4);
            //Move cursor in the center
            printf("\e[H");  //Reset cursor to the origin
            printf("\033[%dB", CENTER_Y); // Move down X column;
            printf("\033[%dC", CENTER_X); // Move right X column;
            break;
        case 55:
            print_number(5, 4);
            //Move cursor in the center
            printf("\e[H");  //Reset cursor to the origin
            printf("\033[%dB", CENTER_Y); // Move down X column;
            printf("\033[%dC", CENTER_X); // Move right X column;
            break;
        case 56:
            print_number(6, 4);
            //Move cursor in the center
            printf("\e[H");  //Reset cursor to the origin
            printf("\033[%dB", CENTER_Y); // Move down X column;
            printf("\033[%dC", CENTER_X); // Move right X column;
            break;
        case 57:
            print_number(7, 4);
            //Move cursor in the center
            printf("\e[H");  //Reset cursor to the origin
            printf("\033[%dB", CENTER_Y); // Move down X column;
            printf("\033[%dC", CENTER_X); // Move right X column;
            break;
        case 58:
            print_number(8, 4);
            //Move cursor in the center
            printf("\e[H");  //Reset cursor to the origin
            printf("\033[%dB", CENTER_Y); // Move down X column;
            printf("\033[%dC", CENTER_X); // Move right X column;
            break;
        case 59:
            print_number(9, 4);
            //Move cursor in the center
            printf("\e[H");  //Reset cursor to the origin
            printf("\033[%dB", CENTER_Y); // Move down X column;
            printf("\033[%dC", CENTER_X); // Move right X column;
            break;
        default:
            break;
        }
    }
    
    
}

void print_separator(unsigned short int blink_sec)
{
    print_number(99, 2);
    printf("\e[H");  //Reset cursor to the origin
    printf("\033[%dB", CENTER_Y); // Move down X column;
    printf("\033[%dC", CENTER_X); // Move right X column;
}

/*
* Printing function for the clock numbers
*/
void print_clock(unsigned short int blink_sec)
{
    //Get current time
    time_t current_time;
    time(&current_time);
    struct tm *t = localtime(&current_time);
    
    print_hours(t);
    print_separator(blink_sec);
    print_minutes(t);

    fflush(0);
    second_blink();
}

void hide_cursor(void){
    printf("\e[?25l"); //Hide cursor
}

void clear_terminal_and_reset_cursor(void){
    printf("\e[2J"); //Clear terminal
    printf("\e[H");  //Reset cursor to the origin
}


int main(){
    hide_cursor();
    struct winsize w;

    while(1)
    {
        //Get the terminal window size
        ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
        CENTER_X = w.ws_col/2;
        CENTER_Y = w.ws_row/2;
        //Clear the old output and set curso to 0x0 positin
        clear_terminal_and_reset_cursor();
        print_clock(blink_sec);
        sleep(1);
    }
}