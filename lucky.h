#define RED_NUM_MAX 33
#define RED_NUM_MIN 1
#define NUM_NOT 0xff

#define BLUE_NUM_MAX 16
#define BLUE_NUM_MIN 1

#define FRONT_NUM_MAX 15
#define FRONT_NUM_MIN 1

#define BACK_NUM_MAX 12
#define BACK_NUM_MIN 1

typedef unsigned char num;
typedef unsigned char col;
typedef unsigned char sty;
typedef unsigned char ara;
typedef char str[10];

/* 6 + 1 -> 1 - 33 : 1 - 16 */
/* 5 + 2 -> 1 - 35 : 1 - 12 */
enum double_color
{
    COLOR_NOT  = 0,
    COLOR_RED  = 2,
    COLOR_BLUE = 6
};

enum double_area
{
    AREA_NOT    = 0,
    AREA_FRONT  = 10, /* 0xa */
    AREA_BACK   = 11  /* 0xb */
};

enum double_style
{
    STYLE_NOT = 0,
    STYLE_SSQ = 12, /* 0xc double color */
    STYLE_DLT = 13, /* 0xd double area  */
    STYLE_CR  = 0xc2,
    STYLE_CB  = 0xc6,
    STYLE_DF  = 0xda,
    STYLE_DB  = 0xdb
};

static str colors[] = {"null", "red", "blue"};
static str areas[] = {"null", "front", "back"};

const num dc_bet[] = {6, 1};
const num da_bet[] = {5, 2};

static num red_numbers[] = { 1,  2,  3,  4 , 5,  6,  7,  8,  9, 10,
                            11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
                            21, 22, 23, 24, 25, 26, 27, 28, 29, 30,
                            31, 32, 33 };
                            
static num blue_numbers[] = { 1,  2,  3,  4 , 5,  6,  7,  8,  9, 10,
                             11, 12, 13, 14, 15, 16};                        

static num front_numbers[] = {1,  2,  3,  4 , 5,  6,  7,  8,  9, 10,
                             11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
                             21, 22, 23, 24, 25, 26, 27, 28, 29, 30,
                             31, 32, 33, 34, 35 };

static num back_numbers[] = { 1,  2,  3,  4 , 5,  6,  7,  8,  9, 10,
                             11, 12 };
      