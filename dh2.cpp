// dh2.cpp - originally written and placed in the public domain by Wei Dai

#include "pch.h"
#include "cryptlib.h"
#include "misc.h"
#include "dh2.h"

NAMESPACE_BEGIN(CryptoPP_NV_2)

#if defined(CryptoPP_NV_2_DEBUG) && !defined(CryptoPP_NV_2_DOXYGEN_PROCESSING)
struct NullCryptoParameters : public CryptoParameters
{
	void AssignFrom(const NameValuePairs &source) {
		CryptoPP_NV_2_UNUSED(source);
	}
	bool Validate(RandomNumberGenerator &rng, unsigned int level) const {
		CryptoPP_NV_2_UNUSED(rng); CryptoPP_NV_2_UNUSED(level);
		return false;
	}
	bool GetVoidValue(const char *name, const std::type_info &valueType, void *pValue) const {
		CryptoPP_NV_2_UNUSED(name); CryptoPP_NV_2_UNUSED(valueType); CryptoPP_NV_2_UNUSED(pValue);
		return false;
	}
};

struct NullSimpleKeyAgreementDomain : public TwoBases<NullCryptoParameters, SimpleKeyAgreementDomain>
{
	CryptoParameters & AccessCryptoParameters() {
		return *this;
	}
	unsigned int AgreedValueLength() const {
		return 1;
	}
	unsigned int PrivateKeyLength() const {
		return 1;
	}
	unsigned int PublicKeyLength() const {
		return 1;
	}
	void GeneratePrivateKey(RandomNumberGenerator &rng, byte *privateKey) const {
		CryptoPP_NV_2_UNUSED(rng); CryptoPP_NV_2_UNUSED(privateKey);
	}
	void GeneratePublicKey(RandomNumberGenerator &rng, const byte *privateKey, byte *publicKey) const {
		CryptoPP_NV_2_UNUSED(rng); CryptoPP_NV_2_UNUSED(privateKey); CryptoPP_NV_2_UNUSED(publicKey);
	}
	bool Agree(byte *agreedValue, const byte *privateKey, const byte *otherPublicKey, bool validateOtherPublicKey=true) const {
		CryptoPP_NV_2_UNUSED(agreedValue); CryptoPP_NV_2_UNUSED(privateKey);
		CryptoPP_NV_2_UNUSED(otherPublicKey); CryptoPP_NV_2_UNUSED(validateOtherPublicKey);
		return false;
	}
};

void DH2_TestInstantiations()
{
	NullSimpleKeyAgreementDomain dom;
	DH2 dh(dom);
}
#endif

bool DH2::Agree(byte *agreedValue,
		const byte *staticSecretKey, const byte *ephemeralSecretKey,
		const byte *staticOtherPublicKey, const byte *ephemeralOtherPublicKey,
		bool validateStaticOtherPublicKey) const
{
	return d1.Agree(agreedValue, staticSecretKey, staticOtherPublicKey, validateStaticOtherPublicKey)
		&& d2.Agree(agreedValue+d1.AgreedValueLength(), ephemeralSecretKey, ephemeralOtherPublicKey, true);
}

NAMESPACE_END
