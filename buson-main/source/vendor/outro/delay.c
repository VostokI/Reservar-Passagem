#include "delay.h"



void sleep_ms(int milliseconds){ // cross-platform sleep function
    #ifdef WIN32
        Sleep(milliseconds);
    #elif _POSIX_C_SOURCE >= 199309L
        struct timespec ts;
        ts.tv_sec = milliseconds / 1000;
        ts.tv_nsec = (milliseconds % 1000) * 1000000;
        nanosleep(&ts, NULL);
    #else
        if (milliseconds >= 1000)
            sleep(milliseconds / 1000);
            usleep((milliseconds % 1000) * 1000);
    #endif
}