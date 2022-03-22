// dll.h - originally written and placed in the public domain by Wei Dai

/// \file dll.h
/// \brief Functions and definitions required for building the FIPS-140 DLL on Windows

#ifndef CryptoPP_NV_2_DLL_H
#define CryptoPP_NV_2_DLL_H

#if !defined(CryptoPP_NV_2_IMPORTS) && !defined(CryptoPP_NV_2_EXPORTS) && !defined(CryptoPP_NV_2_DEFAULT_NO_DLL)
#ifdef CryptoPP_NV_2_CONFIG_H
#error To use the DLL version of Crypto++, this file must be included before any other Crypto++ header files.
#endif
#define CryptoPP_NV_2_IMPORTS
#endif

#include "aes.h"
#include "cbcmac.h"
#include "ccm.h"
#include "cmac.h"
#include "channels.h"
#include "des.h"
#include "dh.h"
#include "dsa.h"
#include "ec2n.h"
#include "eccrypto.h"
#include "ecp.h"
#include "files.h"
#include "fips140.h"
#include "gcm.h"
#include "hex.h"
#include "hmac.h"
#include "modes.h"
#include "mqueue.h"
#include "nbtheory.h"
#include "osrng.h"
#include "pkcspad.h"
#include "pssr.h"
#include "randpool.h"
#include "rsa.h"
#include "rw.h"
#include "sha.h"
#include "skipjack.h"

#ifdef CryptoPP_NV_2_IMPORTS

#ifdef _DLL
// cause CRT DLL to be initialized before Crypto++ so that we can use malloc and free during DllMain()
#ifdef CryptoPP_NV_2_DEBUG
# pragma comment(lib, "msvcrtd")
# pragma comment(lib, "CryptoPP_NV_2")
#else
# pragma comment(lib, "msvcrt")
# pragma comment(lib, "CryptoPP_NV_2")
#endif
#endif

#endif		// #ifdef CryptoPP_NV_2_IMPORTS

#include <new>	// for new_handler

NAMESPACE_BEGIN(CryptoPP_NV_2)

typedef void * (CryptoPP_NV_2_API * PNew)(size_t);
typedef void (CryptoPP_NV_2_API * PDelete)(void *);
typedef void (CryptoPP_NV_2_API * PGetNewAndDelete)(PNew &, PDelete &);
typedef std::new_handler (CryptoPP_NV_2_API * PSetNewHandler)(std::new_handler);
typedef void (CryptoPP_NV_2_API * PSetNewAndDelete)(PNew, PDelete, PSetNewHandler);

NAMESPACE_END

#endif
