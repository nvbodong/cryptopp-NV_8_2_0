// serpent.h - originally written and placed in the public domain by Wei Dai

/// \file serpent.h
/// \brief Classes for the Serpent block cipher

#ifndef CryptoPP_NV_2_SERPENT_H
#define CryptoPP_NV_2_SERPENT_H

#include "seckey.h"
#include "secblock.h"

NAMESPACE_BEGIN(CryptoPP_NV_2)

/// \brief Serpent block cipher information
/// \since Crypto++ 3.1
struct Serpent_Info : public FixedBlockSize<16>, public VariableKeyLength<16, 16, 32, 8>, public FixedRounds<32>
{
	CryptoPP_NV_2_STATIC_CONSTEXPR const char* StaticAlgorithmName() {return "Serpent";}
};

/// \brief Serpent block cipher
/// \sa <a href="http://www.CryptoPP_NV_2.com/wiki/Serpent">Serpent</a>
/// \since Crypto++ 3.1
class Serpent : public Serpent_Info, public BlockCipherDocumentation
{
	class CryptoPP_NV_2_NO_VTABLE Base : public BlockCipherImpl<Serpent_Info>
	{
	public:
		void UncheckedSetKey(const byte *userKey, unsigned int length, const NameValuePairs &params);

	protected:
		FixedSizeSecBlock<word32, 33*4> m_key;
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

typedef Serpent::Encryption SerpentEncryption;
typedef Serpent::Decryption SerpentDecryption;

NAMESPACE_END

#endif
