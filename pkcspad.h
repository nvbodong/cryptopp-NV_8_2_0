// pkcspad.h - originally written and placed in the public domain by Wei Dai

/// \file pkcspad.h
/// \brief Classes for PKCS padding schemes
/// \details PKCS #1 v1.5, v2.0 and P1363a allow MD2, MD5, SHA1, SHA224, SHA256, SHA384,
///   SHA512, Tiger and RipeMd-160 to be instantiated.

#ifndef CryptoPP_NV_2_PKCSPAD_H
#define CryptoPP_NV_2_PKCSPAD_H

#include "cryptlib.h"
#include "pubkey.h"
#include "hashfwd.h"

#ifdef CryptoPP_NV_2_IS_DLL
#include "sha.h"
#endif

NAMESPACE_BEGIN(CryptoPP_NV_2)

/// \brief PKCS #1 v1.5 Encryption Padding Scheme
/// \sa <a href="http://www.weidai.com/scan-mirror/ca.html#cem_PKCS1-1.5">EME-PKCS1-v1_5</a>
class PKCS_EncryptionPaddingScheme : public PK_EncryptionMessageEncodingMethod
{
public:
	CryptoPP_NV_2_STATIC_CONSTEXPR const char* StaticAlgorithmName() {return "EME-PKCS1-v1_5";}

	size_t MaxUnpaddedLength(size_t paddedLength) const;
	void Pad(RandomNumberGenerator &rng, const byte *raw, size_t inputLength, byte *padded, size_t paddedLength, const NameValuePairs &parameters) const;
	DecodingResult Unpad(const byte *padded, size_t paddedLength, byte *raw, const NameValuePairs &parameters) const;
};

/// \brief PKCS #1 decoration data structure
template <class H> class PKCS_DigestDecoration
{
public:
	static const byte decoration[];
	static const unsigned int length;
};

// PKCS_DigestDecoration can be instantiated with the following
// classes as specified in PKCS #1 v2.0 and P1363a
// SHA1, SHA224, SHA256, SHA384, SHA512, Tiger, RIPEMD160, MD2, MD5

#if defined(CryptoPP_NV_2_IS_DLL)
CryptoPP_NV_2_DLL_TEMPLATE_CLASS PKCS_DigestDecoration<SHA1>;
CryptoPP_NV_2_DLL_TEMPLATE_CLASS PKCS_DigestDecoration<SHA224>;
CryptoPP_NV_2_DLL_TEMPLATE_CLASS PKCS_DigestDecoration<SHA256>;
CryptoPP_NV_2_DLL_TEMPLATE_CLASS PKCS_DigestDecoration<SHA384>;
CryptoPP_NV_2_DLL_TEMPLATE_CLASS PKCS_DigestDecoration<SHA512>;
// http://github.com/weidai11/CryptoPP_NV_2/issues/517
CryptoPP_NV_2_DLL_TEMPLATE_CLASS PKCS_DigestDecoration<SHA3_256>;
CryptoPP_NV_2_DLL_TEMPLATE_CLASS PKCS_DigestDecoration<SHA3_384>;
CryptoPP_NV_2_DLL_TEMPLATE_CLASS PKCS_DigestDecoration<SHA3_512>;
#endif

// https://github.com/weidai11/CryptoPP_NV_2/issues/300 and
// https://github.com/weidai11/CryptoPP_NV_2/issues/533
#if defined(__clang__)
template<> const byte PKCS_DigestDecoration<SHA1>::decoration[];
template<> const unsigned int PKCS_DigestDecoration<SHA1>::length;
template<> const byte PKCS_DigestDecoration<SHA224>::decoration[];
template<> const unsigned int PKCS_DigestDecoration<SHA224>::length;
template<> const byte PKCS_DigestDecoration<SHA256>::decoration[];
template<> const unsigned int PKCS_DigestDecoration<SHA256>::length;
template<> const byte PKCS_DigestDecoration<SHA384>::decoration[];
template<> const unsigned int PKCS_DigestDecoration<SHA384>::length;
template<> const byte PKCS_DigestDecoration<SHA512>::decoration[];
template<> const unsigned int PKCS_DigestDecoration<SHA512>::length;

// http://github.com/weidai11/CryptoPP_NV_2/issues/517
template<> const byte PKCS_DigestDecoration<SHA3_256>::decoration[];
template<> const unsigned int PKCS_DigestDecoration<SHA3_256>::length;
template<> const byte PKCS_DigestDecoration<SHA3_384>::decoration[];
template<> const unsigned int PKCS_DigestDecoration<SHA3_384>::length;
template<> const byte PKCS_DigestDecoration<SHA3_512>::decoration[];
template<> const unsigned int PKCS_DigestDecoration<SHA3_512>::length;

template<> const byte PKCS_DigestDecoration<Weak1::MD2>::decoration[];
template<> const unsigned int PKCS_DigestDecoration<Weak1::MD2>::length;
template<> const byte PKCS_DigestDecoration<Weak1::MD5>::decoration[];
template<> const unsigned int PKCS_DigestDecoration<Weak1::MD5>::length;
#endif

/// \brief PKCS #1 v1.5 Signature Encoding Scheme
/// \sa <a href="http://www.weidai.com/scan-mirror/sig.html#sem_PKCS1-1.5">EMSA-PKCS1-v1_5</a>
class CryptoPP_NV_2_DLL PKCS1v15_SignatureMessageEncodingMethod : public PK_DeterministicSignatureMessageEncodingMethod
{
public:
	CryptoPP_NV_2_STATIC_CONSTEXPR const char* CryptoPP_NV_2_API StaticAlgorithmName() {return "EMSA-PKCS1-v1_5";}

	size_t MinRepresentativeBitLength(size_t hashIdentifierSize, size_t digestSize) const
		{return 8 * (digestSize + hashIdentifierSize + 10);}

	void ComputeMessageRepresentative(RandomNumberGenerator &rng,
		const byte *recoverableMessage, size_t recoverableMessageLength,
		HashTransformation &hash, HashIdentifier hashIdentifier, bool messageEmpty,
		byte *representative, size_t representativeBitLength) const;

	struct HashIdentifierLookup
	{
		template <class H> struct HashIdentifierLookup2
		{
			static HashIdentifier Lookup()
			{
				return HashIdentifier(PKCS_DigestDecoration<H>::decoration, PKCS_DigestDecoration<H>::length);
			}
		};
	};
};

/// \brief PKCS #1 version 1.5, for use with RSAES and RSASS
/// \dontinclude pkcspad.h

struct PKCS1v15 : public SignatureStandard, public EncryptionStandard
{
	typedef PKCS_EncryptionPaddingScheme EncryptionMessageEncodingMethod;
	typedef PKCS1v15_SignatureMessageEncodingMethod SignatureMessageEncodingMethod;
};

NAMESPACE_END

#endif
