#include "stdio.h"
#include "string.h"
#include "unistd.h"
#include "sys/time.h"
#include "lucky.h"

typedef struct dc_win
{
    num red[6];
    num blue[1];
} dc_num;

typedef struct da_win
{
    num front[5];
    num back[2];
} da_num;

class bet
{
public:
    dc_num rdc;
    da_num rda;

    static num get_index(num sum)
    {
        struct timeval now;
        num index = NUM_NOT;

        gettimeofday(&now, NULL);
        //usleep(now.tv_usec);

        index = now.tv_sec % now.tv_usec % sum;

        return index;
    };

    void init(num *arr, num len)
    {
        num i = 0;
        for (i = 0; i < len; i++)
            arr[i] = 0;
    }

    bet()
    {
        init(rdc.red, sizeof(rdc.red));
        init(rdc.blue, sizeof(rdc.blue));
        init(rda.front, sizeof(rda.front));
        init(rda.back, sizeof(rda.back));
    }


    void bet_common(num *arr, num len, num max)
    {
        num i = 0, j = 0;
        class number *pool = new number();

        for (i = max; i > 0; i--)
            pool->add(i);

        for (i = 0; i < len; i++)
        {
            j = this->get_index(max - i);

            arr[i] = pool->cir(j);

            pool->del(arr[i]);
        }

        delete pool;

        qsort(arr, len, sizeof(char), cmp);
    };

    void dc()
    {
        init(rdc.red, sizeof(rdc.red));
        init(rdc.blue, sizeof(rdc.blue));

        bet_common(rdc.red, sizeof(rdc.red), RED_NUM_MAX);
        bet_common(rdc.blue, sizeof(rdc.blue), BLUE_NUM_MAX);
        num i = 0;

        printf("[ ");
        for (i = 0; i < dc_bet[0]; i++)
        {
            printf("%2d ", rdc.red[i]);
        }

        printf("] | [");

        for (i = 0; i < dc_bet[1]; i++)
        {
            printf("%2d ", rdc.blue[i]);
        }

        printf(" ]\n");
    };


    void da()
    {
        init(rda.front, sizeof(rda.front));
        init(rda.back, sizeof(rda.back));

        bet_common(rda.front, sizeof(rda.front), FRONT_NUM_MAX);
        bet_common(rda.back, sizeof(rda.back), BACK_NUM_MAX);
        num i = 0;

        printf("[ ");

        for (i = 0; i < da_bet[0]; i++)
        {
            printf("%2d ", rda.front[i]);
        }

        printf("]| [");

        for (i = 0; i < da_bet[1]; i++)
        {
            printf("%2d ", rda.back[i]);
        }

        printf("]\n");
    };
};

char* version = "This is first test version";
#include <mcheck.h>
int main()
{
    mtrace();
    class bet one_bet;

    one_bet.dc();
    one_bet.da();

    puts(version);
    return 0;
}