#include "stdio.h"
#include "string.h"
#include "unistd.h"
#include "sys/time.h"
#include "lucky.h"

class ball
{
public:
    num value;
    sty style;
    str sname;
    
    num number()
    {
        return this->value;
    };
    
    char* name()
    {
        return this->sname;
    }
    
    static num get_ball_index(sty style)
    {
        struct timeval now; 
        num index = NUM_NOT;
    
        gettimeofday(&now, NULL);
        usleep(now.tv_usec);
    
        switch (style)
        {
            case STYLE_CR:
            index = now.tv_sec % now.tv_usec % sizeof(red_numbers);
            break;
            case STYLE_CB:
            index = now.tv_sec % now.tv_usec % sizeof(blue_numbers);
            break;
            case STYLE_DF:
            index = now.tv_sec % now.tv_usec % sizeof(front_numbers);
            break;
            case STYLE_DB:
            index = now.tv_sec % now.tv_usec % sizeof(back_numbers);
            break;
            default:
            break;
        }
        
        return index;
    };
};

class bet
{
public:
    class ball *red;
    class ball *blue;
    class ball *front;
    class ball *back;
    
    static num get_index(num sum)
    {
        struct timeval now; 
        num index = NUM_NOT;
    
        gettimeofday(&now, NULL);
        usleep(now.tv_usec);
        
        index = now.tv_sec % now.tv_usec % sum;
        
        return index;
    };
    
    bet()
    {
        red = new ball[dc_bet[0]];
        blue = new ball[dc_bet[1]];
        
        front = new ball[da_bet[0]];
        back = new ball[da_bet[1]];
    }
    
    void dc()
    {
        num n = dc_bet[0];
        
        while (n--)
            printf("%2d ", red->number());
        
        n = dc_bet[1];
        
        while (n--)
            printf("+%2d ", blue->number());
        
        printf("\n");
    }
    
    void da()
    {
        num n = da_bet[0];
        
        while (n--)
            printf("%2d ", front->number());
        
        n = da_bet[1];
        
        while (n--)
            printf("+%2d ", back->number());
        
        printf("\n");
    }   
    
};

int test(int argc, char** argv)
{  
    int i = 0;
    
    for (i = 0; i < 6; i++)
    {
        printf("%2d ", red_numbers[ball::get_ball_index(STYLE_CR)]);
    }
    
    printf(" + %2d \n", blue_numbers[ball::get_ball_index(STYLE_CB)]);
    
    for (i = 0; i < 5; i++)
    {
        printf("%2d ", front_numbers[ball::get_ball_index(STYLE_DF)]);
    }
    
    printf(" + %2d %2d\n", back_numbers[ball::get_ball_index(STYLE_DB)],
                        back_numbers[ball::get_ball_index(STYLE_DB)]);
    return 0;
}

int main()
{
    class bet one_bet;
    
    one_bet.dc();
    one_bet.da();
    return 0;
}