// tiger.h - originally written and placed in the public domain by Wei Dai

/// \file tiger.h
/// \brief Classes for the Tiger message digest
/// \since Crypto++ 2.1

#ifndef CryptoPP_NV_2_TIGER_H
#define CryptoPP_NV_2_TIGER_H

#include "config.h"
#include "iterhash.h"

// Clang 3.3 integrated assembler crash on Linux. Clang 3.4 due to compiler
// error with .intel_syntax, http://llvm.org/bugs/show_bug.cgi?id=24232
#if CryptoPP_NV_2_BOOL_X32 || defined(CryptoPP_NV_2_DISABLE_MIXED_ASM)
# define CryptoPP_NV_2_DISABLE_TIGER_ASM 1
#endif

NAMESPACE_BEGIN(CryptoPP_NV_2)

/// \brief Tiger message digest
/// \sa <a href="http://www.cryptolounge.org/wiki/Tiger">Tiger</a>
/// \since Crypto++ 2.1
class Tiger : public IteratedHashWithStaticTransform<word64, LittleEndian, 64, 24, Tiger>
{
public:
	CryptoPP_NV_2_STATIC_CONSTEXPR const char* StaticAlgorithmName() {return "Tiger";}
	std::string AlgorithmProvider() const;

	static void InitState(HashWordType *state);
	static void Transform(word64 *digest, const word64 *data);
	void TruncatedFinal(byte *hash, size_t size);

protected:
	static const word64 table[4*256+3];
};

NAMESPACE_END

#endif
