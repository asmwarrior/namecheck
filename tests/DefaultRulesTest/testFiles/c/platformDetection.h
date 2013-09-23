#ifndef _PLATFORM_DETECTION_H
#define _PLATFORM_DETECTION_H


#define PLATFORM_LINUX      1
#define PLATFORM_MPLAB1     2
#define PLATFORM_MPLAB2     3
#define PLATFORM_UNKNOWN    4
#define DSPIC33E            5
#define DSPIC33F            6
#define DSPIC33E128         7

#if (defined (__linux__) \
    || defined (linux)   \
    || defined (__linux))
#   define PLATFORM    PLATFORM_LINUX
#elif(defined _MPLAB_)
#   define PLATFORM    PLATFORM_MPLAB1
#elif(defined _MPLAB2)
#   define PLATFORM    PLATFORM_MPLAB2
#else
#   define INLINE
#   define PLATFORM    PLATFORM_UNKNOWN
#endif



/* Conditionally define language-specific keywords overwrites */

#if PLATFORM == PLATFORM_LINUX
#   ifndef TESTING
#       define INLINE __inline
#       define STATIC static
#       define _ISRT
#       define _ALIG
#       define GETEDSPAGE(X)    NULL
#       define CLRWDT()
#       define TablePage(X)     NULL
#       define TableOffset(X)   NULL
#       define WriteLatch(X,Y)  NULL
#       define WriteMemory()    NULL
#       define ReadMemory(X)    NULL
#   else
#       define INLINE   /* gdb has problems with inline definitions */
#       define STATIC   /* tests need to have access to the internal symbols */
#       define _ISRT
#       define _ALIG
#       define GETEDSPAGE(X)    NULL
#       define CLRWDT()
#       define TablePage(X)     NULL
#       define TableOffset(X)   NULL
#       define WriteLatch(X,Y)  NULL
#       define WriteMemory()    NULL
#       define ReadMemory(X)    NULL
#   endif
#elif PLATFORM == PLATFORM_MPLAB1
#   define INLINE __inline__
#   define STATIC static
#   define _ISRT __attribute__((__interrupt__, __no_auto_psv__))
#   define _ALIG __attribute__((aligned(NUM_OF_ECAN_BUFFERS * NUM_OF_ALIGNED_BYTES)))
#   define GETEDSPAGE(X) __builtin_edspage(X);
#   define CLRWDT() ClrWdt()
#   define TablePage(X) __builtin_tblpage(X)
#   define TableOffset(X) __builtin_tbloffset(X)
#   define WriteLatch(X,Y) __builtin_tblwtl(X,Y)
#   define WriteMemory() __builtin_write_NVM()
#   define ReadMemory(X)__builtin_tblrdl(X)
#elif PLATFORM == PLATFORM_MPLAB2
#   define INLINE inline
#   define STATIC static
#   define _ISRT __attribute__((__interrupt__, __no_auto_psv__))
#   define _ALIG __attribute__((aligned(NUM_OF_ECAN_BUFFERS * NUM_OF_ALIGNED_BYTES)))
#   define GETEDSPAGE(X) __builtin_edspage(X);
#   define CLRWDT() ClrWdt()
#   define TablePage(X) __builtin_tblpage(X)
#   define TableOffset(X) __builtin_tbloffset(X)
#   define WriteLatch(X,Y) __builtin_tblwtl(X,Y)
#   define WriteMemory() __builtin_write_NVM()
#   define ReadMemory(X)__builtin_tblrdl(X)
#else
#   define INLINE
#   define STATIC static
#   define _ISRT
#endif


/* Invalid combinations detection */

#if PLATFORM != PLATFORM_LINUX && defined(TESTING)
#   error TESTING can only be used under Linux.
#endif

#endif /*endif _PLATFORM_DETECTION */

