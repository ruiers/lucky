#include "stdio.h"
#include "string.h"
#include "unistd.h"
#include "sys/time.h"
#include "lucky.h"

class bet
{
public:
    num red[6];
    num blue[1];
    num front[5];
    num back[2];

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
        init(red, sizeof(red));
        init(blue, sizeof(blue));
        init(front, sizeof(front));
        init(back, sizeof(back));
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
        init(red, sizeof(red));
        init(blue, sizeof(blue));

        bet_common(red, sizeof(red), RED_NUM_MAX);
        bet_common(blue, sizeof(blue), BLUE_NUM_MAX);
        num i = 0;

        printf("[ ");
        for (i = 0; i < dc_bet[0]; i++)
        {
            printf("%2d ", red[i]);
        }

        printf("] | [");

        for (i = 0; i < dc_bet[1]; i++)
        {
            printf("%2d ", blue[i]);
        }

        printf(" ]\n");
    };


    void da()
    {
        init(front, sizeof(front));
        init(back, sizeof(back));

        bet_common(front, sizeof(front), FRONT_NUM_MAX);
        bet_common(back, sizeof(back), BACK_NUM_MAX);
        num i = 0;

        printf("[ ");

        for (i = 0; i < da_bet[0]; i++)
        {
            printf("%2d ", front[i]);
        }

        printf("]| [");

        for (i = 0; i < da_bet[1]; i++)
        {
            printf("%2d ", back[i]);
        }

        printf("]\n");
    };
};

#include <mcheck.h>
int main()
{
    mtrace();
    class bet one_bet;

    one_bet.dc();
    one_bet.da();
    return 0;
}