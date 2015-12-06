#if defined(__TURBOC__)
/* Under Borland/Turbo C++, cpu time is not available, just clock */
#include <time.h>
float cputime (float *this_time)
{
   float   last_time;

   last_time = *this_time;
   *this_time = clock () / (double) CLK_TCK;
   return *this_time - last_time;
}
float ClockTime (float *this_time)
{
   return cputime(this_time);
}
#else
#define SGI

/* BSD UNIX procedures for time: */

#if defined(BSD)
#include <sys/types.h>
#include <sys/timeb.h>
float ClockTime (float *Current)
{
   struct timeb tp;
   float Last, Rtn;

   Last = *Current;
   ftime (&tp);
   *Current = tp.time + 1.0e-03 * tp.millitm;
   Rtn = *Current - Last;
   return Rtn;
}
#elif defined(SGI)
#include <sys/types.h>
#include <sys/times.h>
#include <time.h>
#include <limits.h>

float ClockTime (float *Current)
{
   struct tms buffer;
   float Last;
   clock_t Ticks;

   Last = *Current;
   Ticks = times(&buffer);
   *Current = (double) Ticks / CLK_TCK;
   return *Current - Last;
}
#endif

#include <sys/time.h>
#include <sys/resource.h>
#define  RUSAGE_SELF 0
float cputime (float *this_time)
{
   float last_time;
   struct rusage scratch;

   last_time = *this_time;
   getrusage(RUSAGE_SELF, &scratch);
   *this_time = scratch.ru_utime.tv_sec +
                scratch.ru_stime.tv_sec +
              ( scratch.ru_utime.tv_usec +
                scratch.ru_stime.tv_usec ) * 1.0e-06;
   return *this_time - last_time;
}
#endif
