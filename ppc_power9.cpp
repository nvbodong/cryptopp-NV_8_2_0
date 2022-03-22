// ppc_power9.cpp - written and placed in the public domain by
//                  Jeffrey Walton, Uri Blumenthal and Marcel Raad.
//
//    This source file uses intrinsics and built-ins to gain access to
//    Power9 instructions. A separate source file is needed because
//    additional CXXFLAGS are required to enable the appropriate
//    instructions sets in some build configurations.

#include "pch.h"
#include "config.h"

#ifdef CryptoPP_NV_2_GNU_STYLE_INLINE_ASSEMBLY
# include <signal.h>
# include <setjmp.h>
#endif

#if defined(_ARCH_PWR9)
# include "ppc_simd.h"
#endif

// Squash MS LNK4221 and libtool warnings
extern const char PPC_POWER9_FNAME[] = __FILE__;

NAMESPACE_BEGIN(CryptoPP_NV_2)

// ************************* Feature Probes ************************* //

#ifdef CryptoPP_NV_2_GNU_STYLE_INLINE_ASSEMBLY
extern "C" {
    typedef void (*SigHandler)(int);

    static jmp_buf s_jmpSIGILL;
    static void SigIllHandler(int)
    {
        longjmp(s_jmpSIGILL, 1);
    }
}
#endif  // CryptoPP_NV_2_MS_STYLE_INLINE_ASSEMBLY

#if (CryptoPP_NV_2_BOOL_PPC32 || CryptoPP_NV_2_BOOL_PPC64)

bool CPU_ProbePower9()
{
#if defined(CryptoPP_NV_2_NO_CPU_FEATURE_PROBES)
    return false;
#elif defined(CryptoPP_NV_2_POWER9_AVAILABLE)
# if defined(CryptoPP_NV_2_GNU_STYLE_INLINE_ASSEMBLY)
    // longjmp and clobber warnings. Volatile is required.
    // http://github.com/weidai11/CryptoPP_NV_2/issues/24 and http://stackoverflow.com/q/7721954
    volatile int result = true;

    volatile SigHandler oldHandler = signal(SIGILL, SigIllHandler);
    if (oldHandler == SIG_ERR)
        return false;

    volatile sigset_t oldMask;
    if (sigprocmask(0, NULLPTR, (sigset_t*)&oldMask))
        return false;

    if (setjmp(s_jmpSIGILL))
        result = false;
    else
    {
        // This is "darn r3, 0". It provides a conditioned 32-bit
        // word. It is available on both 32-bit and 64-bit.
#if CryptoPP_NV_2_BIG_ENDIAN
        __asm__ __volatile__ (".byte 0x7c, 0x60, 0x05, 0xe6  \n" : : : "r3");
#else
        __asm__ __volatile__ (".byte 0xe6, 0x05, 0x60, 0x7c  \n" : : : "r3");
#endif
        result = true;
    }

    sigprocmask(SIG_SETMASK, (sigset_t*)&oldMask, NULLPTR);
    signal(SIGILL, oldHandler);
    return result;
# endif
#else
    return false;
#endif  // _ARCH_PWR9
}

// The DARN probe is not guarded with a preprocessor macro at the moment. We
// don't use CryptoPP_NV_2_POWER9_AVAILABLE because old compilers, like GCC 4.8 on
// CentOS 7, will report NO even though we can produce the random numbers.
// Other Power9 implementations which use builtins will use the preprocessor
// macro guard. This strategy also gets into a situation where Power9 is not
// available but DARN is.
bool CPU_ProbeDARN()
{
#if defined(CryptoPP_NV_2_NO_CPU_FEATURE_PROBES)
    return false;
#else
# if defined(CryptoPP_NV_2_GNU_STYLE_INLINE_ASSEMBLY)
    // longjmp and clobber warnings. Volatile is required.
    // http://github.com/weidai11/CryptoPP_NV_2/issues/24 and http://stackoverflow.com/q/7721954
    volatile int result = true;

    volatile SigHandler oldHandler = signal(SIGILL, SigIllHandler);
    if (oldHandler == SIG_ERR)
        return false;

    volatile sigset_t oldMask;
    if (sigprocmask(0, NULLPTR, (sigset_t*)&oldMask))
        return false;

    if (setjmp(s_jmpSIGILL))
        result = false;
    else
    {
        // This is "darn r3, 0". It provides a conditioned 32-bit
        // word. It is available on both 32-bit and 64-bit.
#if CryptoPP_NV_2_BIG_ENDIAN
        __asm__ __volatile__ (".byte 0x7c, 0x60, 0x05, 0xe6  \n" : : : "r3");
#else
        __asm__ __volatile__ (".byte 0xe6, 0x05, 0x60, 0x7c  \n" : : : "r3");
#endif
        result = true;
    }

    sigprocmask(SIG_SETMASK, (sigset_t*)&oldMask, NULLPTR);
    signal(SIGILL, oldHandler);
    return result;
# endif
#endif  // DARN
}

#endif  // PPC32 or PPC64

NAMESPACE_END
