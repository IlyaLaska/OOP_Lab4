#define DEBUG

//RL -release log
//DL - debug log

#ifndef DEBUG//release

    #define RL
    #define DL if(0)

#else

    #define RL if(0)
    #define DL

#endif