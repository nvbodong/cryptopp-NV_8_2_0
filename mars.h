// mars.h - originally written and placed in the public domain by Wei Dai

/// \file mars.h
/// \brief Classes for the MARS block cipher (IBM AES submission)
/// \since Crypto++ 3.0

#ifndef CryptoPP_NV_2_MARS_H
#define CryptoPP_NV_2_MARS_H

#include "seckey.h"
#include "secblock.h"

NAMESPACE_BEGIN(CryptoPP_NV_2)

/// \brief MARS block cipher information
/// \since Crypto++ 3.0
struct MARS_Info : public FixedBlockSize<16>, public VariableKeyLength<16, 16, 56, 8>
{
	CryptoPP_NV_2_STATIC_CONSTEXPR const char* StaticAlgorithmName() {return "MARS";}
};

/// \brief MARS block cipher
/// \sa <a href="http://www.CryptoPP_NV_2.com/wiki/MARS">MARS</a>
/// \since Crypto++ 3.0
class MARS : public MARS_Info, public BlockCipherDocumentation
{
	class CryptoPP_NV_2_NO_VTABLE Base : public BlockCipherImpl<MARS_Info>
	{
	public:
		void UncheckedSetKey(const byte *userKey, unsigned int length, const NameValuePairs &params);

	protected:
		static const word32 Sbox[512];

		FixedSizeSecBlock<word32, 40> m_k;
	};

	class CryptoPP_NV_2_NO_VTABLE Enc : public Base
	{
	public:
		void ProcessAndXorBlock(const byte *inBlock, const byte *xorBlock, byte *outBlock) const;
	};

	class CryptoPP_NV_2_NO_VTABLE Dec : public Base
	{
	public:
		void ProcessAndXorBlock(const byte *inBlock, const byte *xorBlock, byte *outBlock) const;
	};

public:
	typedef BlockCipherFinal<ENCRYPTION, Enc> Encryption;
	typedef BlockCipherFinal<DECRYPTION, Dec> Decryption;
};

typedef MARS::Encryption MARSEncryption;
typedef MARS::Decryption MARSDecryption;

NAMESPACE_END

#endif