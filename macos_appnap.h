#ifndef __APP_NAP__
#define __APP_NAP__

#if !defined(__cplusplus)
#define C_API extern
#else
#define C_API extern "C"
#endif

C_API void disableAppNap();
C_API void enableAppNap();

#endif
