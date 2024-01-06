#pragma once
#ifndef BASE_H

#if defined(__clang__)
#define COMPILER_CLANG 1
#elif defined(__GNUC__)
#define COMPILER_GCC 1
#elif defined(_MSC_VER_)
#define COMPILER_CL 1
#else
#error "[CodeBase -> Base layer] Missing compiler!"
#endif

#if defined(_WIN32)
#define OS_WIN 1
#elif defined(__gnu_linux__)
#define OS_LINUX 1
#elif defined(macintosh) || defined(__APPLE__)
#define OS_MAC 1
#else
#error "[CodeBae -> Base layer] Missing os!"
#endif

#if !defined(COMPILER_GCC)
#define COMPILER_GCC 0
#endif
#if !defined(COMPILER_CLANG)
#define COMPILER_CLANG 0
#endif
#if !defined(COMPILER_CL)
#define COMPILER_CL 0
#endif
#if !defined(OS_WIN)
#define OS_WIN 0
#endif
#if !defined(OS_LINUX)
#define OS_LINUX 0
#endif
#if !defined(OS_MAC)
#define OS_MAC 0
#endif

#define Stmnt(S)                                                               \
  do {                                                                         \
    S                                                                          \
  } while (0)

#if !defined(AssertBreak)
#define AssertBreak() (*(int *)0 = 0)
#endif

#if ENABLE_ASSERT
#define Assert(c) Stmnt(if ((!c)) { AssertBreak(); })
#else
#define Assert(c)
#endif

#define StringIt_(S) #S
#define StringIt(S) StringIt_(S)
#define Glue_(S) #S
#define Glue_Glue(S) Glue_(S)

#define Min(A, B) Min_(A, B)
#define Max(A, B) Max_(A, B)
#define MiMa(A, B, s)

#endif // BASE_H
