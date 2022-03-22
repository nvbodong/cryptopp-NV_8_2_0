// argnames.h - originally written and placed in the public domain by Wei Dai

/// \file argnames.h
/// \brief Standard names for retrieving values by name when working with \p NameValuePairs

#ifndef CryptoPP_NV_2_ARGNAMES_H
#define CryptoPP_NV_2_ARGNAMES_H

#include "cryptlib.h"

NAMESPACE_BEGIN(CryptoPP_NV_2)

DOCUMENTED_NAMESPACE_BEGIN(Name)

#define CryptoPP_NV_2_DEFINE_NAME_STRING(name)	inline const char *name() {return #name;}

CryptoPP_NV_2_DEFINE_NAME_STRING(ValueNames)			///< string, a list of value names with a semicolon (';') after each name
CryptoPP_NV_2_DEFINE_NAME_STRING(Version)			///< int
CryptoPP_NV_2_DEFINE_NAME_STRING(Seed)				///< ConstByteArrayParameter
CryptoPP_NV_2_DEFINE_NAME_STRING(Key)				///< ConstByteArrayParameter
CryptoPP_NV_2_DEFINE_NAME_STRING(IV)					///< ConstByteArrayParameter, also accepts const byte * for backwards compatibility
CryptoPP_NV_2_DEFINE_NAME_STRING(StolenIV)			///< byte *
CryptoPP_NV_2_DEFINE_NAME_STRING(Nonce)				///< ConstByteArrayParameter
CryptoPP_NV_2_DEFINE_NAME_STRING(Rounds)				///< int
CryptoPP_NV_2_DEFINE_NAME_STRING(FeedbackSize)		///< int
CryptoPP_NV_2_DEFINE_NAME_STRING(WordSize)			///< int, in bytes
CryptoPP_NV_2_DEFINE_NAME_STRING(BlockSize)			///< int, in bytes
CryptoPP_NV_2_DEFINE_NAME_STRING(EffectiveKeyLength)	///< int, in bits
CryptoPP_NV_2_DEFINE_NAME_STRING(KeySize)			///< int, in bits
CryptoPP_NV_2_DEFINE_NAME_STRING(ModulusSize)		///< int, in bits
CryptoPP_NV_2_DEFINE_NAME_STRING(SubgroupOrderSize)	///< int, in bits
CryptoPP_NV_2_DEFINE_NAME_STRING(PrivateExponentSize)///< int, in bits
CryptoPP_NV_2_DEFINE_NAME_STRING(Modulus)			///< Integer
CryptoPP_NV_2_DEFINE_NAME_STRING(PublicExponent)		///< Integer
CryptoPP_NV_2_DEFINE_NAME_STRING(PrivateExponent)	///< Integer
CryptoPP_NV_2_DEFINE_NAME_STRING(PublicElement)		///< Integer
CryptoPP_NV_2_DEFINE_NAME_STRING(SubgroupOrder)		///< Integer
CryptoPP_NV_2_DEFINE_NAME_STRING(Cofactor)			///< Integer
CryptoPP_NV_2_DEFINE_NAME_STRING(SubgroupGenerator)	///< Integer, ECP::Point, or EC2N::Point
CryptoPP_NV_2_DEFINE_NAME_STRING(Curve)				///< ECP or EC2N
CryptoPP_NV_2_DEFINE_NAME_STRING(GroupOID)			///< OID
CryptoPP_NV_2_DEFINE_NAME_STRING(PointerToPrimeSelector)		///< const PrimeSelector *
CryptoPP_NV_2_DEFINE_NAME_STRING(Prime1)				///< Integer
CryptoPP_NV_2_DEFINE_NAME_STRING(Prime2)				///< Integer
CryptoPP_NV_2_DEFINE_NAME_STRING(ModPrime1PrivateExponent)	///< Integer
CryptoPP_NV_2_DEFINE_NAME_STRING(ModPrime2PrivateExponent)	///< Integer
CryptoPP_NV_2_DEFINE_NAME_STRING(MultiplicativeInverseOfPrime2ModPrime1)	///< Integer
CryptoPP_NV_2_DEFINE_NAME_STRING(QuadraticResidueModPrime1)	///< Integer
CryptoPP_NV_2_DEFINE_NAME_STRING(QuadraticResidueModPrime2)	///< Integer
CryptoPP_NV_2_DEFINE_NAME_STRING(PutMessage)			///< bool
CryptoPP_NV_2_DEFINE_NAME_STRING(TruncatedDigestSize)	///< int
CryptoPP_NV_2_DEFINE_NAME_STRING(BlockPaddingScheme)	///< StreamTransformationFilter::BlockPaddingScheme
CryptoPP_NV_2_DEFINE_NAME_STRING(HashVerificationFilterFlags)		///< word32
CryptoPP_NV_2_DEFINE_NAME_STRING(AuthenticatedDecryptionFilterFlags)	///< word32
CryptoPP_NV_2_DEFINE_NAME_STRING(SignatureVerificationFilterFlags)	///< word32
CryptoPP_NV_2_DEFINE_NAME_STRING(InputBuffer)		///< ConstByteArrayParameter
CryptoPP_NV_2_DEFINE_NAME_STRING(OutputBuffer)		///< ByteArrayParameter
CryptoPP_NV_2_DEFINE_NAME_STRING(InputFileName)		///< const char *
CryptoPP_NV_2_DEFINE_NAME_STRING(InputFileNameWide)	///< const wchar_t *
CryptoPP_NV_2_DEFINE_NAME_STRING(InputStreamPointer)	///< std::istream *
CryptoPP_NV_2_DEFINE_NAME_STRING(InputBinaryMode)	///< bool
CryptoPP_NV_2_DEFINE_NAME_STRING(OutputFileName)		///< const char *
CryptoPP_NV_2_DEFINE_NAME_STRING(OutputFileNameWide)	///< const wchar_t *
CryptoPP_NV_2_DEFINE_NAME_STRING(OutputStreamPointer)	///< std::ostream *
CryptoPP_NV_2_DEFINE_NAME_STRING(OutputBinaryMode)	///< bool
CryptoPP_NV_2_DEFINE_NAME_STRING(EncodingParameters)	///< ConstByteArrayParameter
CryptoPP_NV_2_DEFINE_NAME_STRING(KeyDerivationParameters)	///< ConstByteArrayParameter
CryptoPP_NV_2_DEFINE_NAME_STRING(Separator)			///< ConstByteArrayParameter
CryptoPP_NV_2_DEFINE_NAME_STRING(Terminator)			///< ConstByteArrayParameter
CryptoPP_NV_2_DEFINE_NAME_STRING(Uppercase)			///< bool
CryptoPP_NV_2_DEFINE_NAME_STRING(GroupSize)			///< int
CryptoPP_NV_2_DEFINE_NAME_STRING(Pad)				///< bool
CryptoPP_NV_2_DEFINE_NAME_STRING(PaddingByte)		///< byte
CryptoPP_NV_2_DEFINE_NAME_STRING(Log2Base)			///< int
CryptoPP_NV_2_DEFINE_NAME_STRING(EncodingLookupArray)	///< const byte *
CryptoPP_NV_2_DEFINE_NAME_STRING(DecodingLookupArray)	///< const byte *
CryptoPP_NV_2_DEFINE_NAME_STRING(InsertLineBreaks)	///< bool
CryptoPP_NV_2_DEFINE_NAME_STRING(MaxLineLength)		///< int
CryptoPP_NV_2_DEFINE_NAME_STRING(DigestSize)			///< int, in bytes
CryptoPP_NV_2_DEFINE_NAME_STRING(L1KeyLength)		///< int, in bytes
CryptoPP_NV_2_DEFINE_NAME_STRING(TableSize)			///< int, in bytes
CryptoPP_NV_2_DEFINE_NAME_STRING(Blinding)			///< bool, timing attack mitigations, ON by default
CryptoPP_NV_2_DEFINE_NAME_STRING(DerivedKey)			///< ByteArrayParameter, key derivation, derived key
CryptoPP_NV_2_DEFINE_NAME_STRING(DerivedKeyLength)	///< int, key derivation, derived key length in bytes
CryptoPP_NV_2_DEFINE_NAME_STRING(Personalization)	///< ConstByteArrayParameter
CryptoPP_NV_2_DEFINE_NAME_STRING(PersonalizationSize)	///< int, in bytes
CryptoPP_NV_2_DEFINE_NAME_STRING(Salt)				///< ConstByteArrayParameter
CryptoPP_NV_2_DEFINE_NAME_STRING(Tweak)				///< ConstByteArrayParameter
CryptoPP_NV_2_DEFINE_NAME_STRING(SaltSize)			///< int, in bytes
CryptoPP_NV_2_DEFINE_NAME_STRING(TreeMode)			///< byte
CryptoPP_NV_2_DEFINE_NAME_STRING(FileName)			///< const char *
CryptoPP_NV_2_DEFINE_NAME_STRING(FileTime)			///< int
CryptoPP_NV_2_DEFINE_NAME_STRING(Comment)			///< const char *
CryptoPP_NV_2_DEFINE_NAME_STRING(Identity)			///< ConstByteArrayParameter
DOCUMENTED_NAMESPACE_END

NAMESPACE_END

#endif
