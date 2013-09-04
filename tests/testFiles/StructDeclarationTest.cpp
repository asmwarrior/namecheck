struct Test1t /* PASSED */
{
    /* data */
};

struct Test2t /* PASSED */
{
    struct Test3t
    {
        /* data */
    };

    /* data */
};

struct Test4t /* PASSED */
{
    struct Test5t
    {
        struct Test6t
        {
            /* data */
        };

        /* data */
    };

    /* data */
};

struct Test7t /* FAIL */
{
    /* data */
};

struct Test8t /*FAIL*/
{
    struct Test9t
    {
        /* data */
    };
    /* data */

};

struct Test10t /* FAIL */
{
    struct Test11t
    {
        /* data */
    };
    /* data */
};

struct Test12t /* FAIL */
{
    struct Test13t
    {
        /* data */
    };
    /* data */
};

struct Test14t /* FAIL */
{
    struct Test15t
    {
        struct test16t
        {
            /* data */
        };

        /* data */
    };
    /* data */
};