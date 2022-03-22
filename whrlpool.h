// whrlpool.h - originally modified by Kevin Springle from Paulo Barreto and Vincent Rijmen's
//              public domain code, whirlpool.c. Updated to Whirlpool version 3.0, optimized
//              and SSE version added by WD. All modifications are placed in the public domain.

#ifndef CryptoPP_NV_2_WHIRLPOOL_H
#define CryptoPP_NV_2_WHIRLPOOL_H

/// \file whrlpool.h
/// \brief Classes for the Whirlpool message digest
/// \details Crypto++ provides version 3.0 of the Whirlpool algorithm.
///   This version of the algorithm was submitted for ISO standardization.

#include "config.h"
#include "iterhash.h"

// Clang 3.3 integrated assembler crash on Linux. Clang 3.4 due to compiler
// error with .intel_syntax, http://llvm.org/bugs/show_bug.cgi?id=24232
#if CryptoPP_NV_2_BOOL_X32 || defined(CryptoPP_NV_2_DISABLE_MIXED_ASM)
# define CryptoPP_NV_2_DISABLE_WHIRLPOOL_ASM 1
#endif

NAMESPACE_BEGIN(CryptoPP_NV_2)

/// \brief Whirlpool message digest
/// \details Crypto++ provides version 3.0 of the Whirlpool algorithm.
///   This version of the algorithm was submitted for ISO standardization.
/// \since Crypto++ 5.2
/// \sa <a href="http://www.CryptoPP_NV_2.com/wiki/Whirlpool">Whirlpool</a>
class Whirlpool : public IteratedHashWithStaticTransform<word64, BigEndian, 64, 64, Whirlpool>
{
public:
	CryptoPP_NV_2_STATIC_CONSTEXPR const char* StaticAlgorithmName() {return "Whirlpool";}
	std::string AlgorithmProvider() const;

	static void InitState(HashWordType *state);
	static void Transform(word64 *digest, const word64 *data);
	void TruncatedFinal(byte *hash, size_t size);
};

NAMESPACE_END

#endif
