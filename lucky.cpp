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

    void set_value(num v)
    {
        this->value = v;
    };

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
        //usleep(now.tv_usec);

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

    void dc_red()
    {
        num i = 0, j = 0, n = dc_bet[0];
        class number *red_pool = new number();

        for (i = RED_NUM_MAX; i >= RED_NUM_MIN; i--)
            red_pool->add(i);

        for (i = 0; i < n; i++)
        {
            j = this->get_index(RED_NUM_MAX - i);

            red[i].set_value(red_pool->cir(j));

            red_pool->del(red[i].number());
        }

        delete red_pool;
    };

    void dc_blue()
    {
        num i = 0, j = 0, n = dc_bet[1];
        class number *blue_pool = new number();

        for (i = BLUE_NUM_MAX; i >= BLUE_NUM_MIN; i--)
            blue_pool->add(i);

        for (i = 0; i < n; i++)
        {
            j = this->get_index(BLUE_NUM_MAX - i);

            blue[i].set_value(blue_pool->cir(j));

            blue_pool->del(blue[i].number());
        }

        delete blue_pool;
    };

    void dc()
    {
        dc_red();
        dc_blue();

        num i = 0;

        printf("[ ");
        for (i = 0; i < dc_bet[0]; i++)
        {
            printf("%2d ", red[i].number());
        }

        printf("] | [");

        for (i = 0; i < dc_bet[1]; i++)
        {
            printf("%2d ", blue[i].number());
        }

        printf(" ]\n");
    };

    void da_front()
    {
        num i = 0, j = 0, n = da_bet[0];
        class number *front_pool = new number();

        for (i = FRONT_NUM_MAX; i >= FRONT_NUM_MIN; i--)
            front_pool->add(i);

        for (i = 0; i < n; i++)
        {
            j = this->get_index(FRONT_NUM_MAX - i);

            front[i].set_value(front_pool->cir(j));

            front_pool->del(front[i].number());
        }

        delete front_pool;
    };

    void da_back()
    {
        num i = 0, j = 0, n = da_bet[1];
        class number *back_pool = new number();

        for (i = BACK_NUM_MAX; i >= BACK_NUM_MIN; i--)
            back_pool->add(i);

        for (i = 0; i < n; i++)
        {
            j = this->get_index(BACK_NUM_MAX - i);

            back[i].set_value(back_pool->cir(j));

            back_pool->del(back[i].number());
        }

        delete back_pool;
    };

    void da()
    {
        da_front();
        da_back();

        num i = 0;

        printf("[ ");

        for (i = 0; i < da_bet[0]; i++)
        {
            printf("%2d ", front[i].number());
        }

        printf("]| [");

        for (i = 0; i < da_bet[1]; i++)
        {
            printf("%2d ", back[i].number());
        }

        printf("]\n");
    };

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