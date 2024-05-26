// header file for petmanage.c

// cat record
typedef struct
{
    char *breed;
    char *eyeColor;
} CatRecord;

// dog record
typedef struct
{
    char *breed;
    char *tailType;
} DogRecord;

// pet info
typedef struct
{
    char *name;
    char age;
    char *bodyColor;
    char catOrDog;
    union
    {
        CatRecord cat;
        DogRecord dog;
    };
} PetInfo;

// list node
typedef struct ListNode
{
    PetInfo *data;
    struct ListNode *next;
} ListNode;
