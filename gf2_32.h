// gf2_32.h - originally written and placed in the public domain by Wei Dai

/// \file gf2_32.h
/// \brief Classes and functions for schemes over GF(2^32)

#ifndef CryptoPP_NV_2_GF2_32_H
#define CryptoPP_NV_2_GF2_32_H

#include "cryptlib.h"
#include "secblock.h"
#include "misc.h"

NAMESPACE_BEGIN(CryptoPP_NV_2)

/// \brief GF(2^32) with polynomial basis
class GF2_32
{
public:
	typedef word32 Element;
	typedef int RandomizationParameter;

	GF2_32(word32 modulus=0x0000008D) : m_modulus(modulus) {}

	Element RandomElement(RandomNumberGenerator &rng, int ignored = 0) const
		{CryptoPP_NV_2_UNUSED(ignored); return rng.GenerateWord32();}

	bool Equal(Element a, Element b) const
		{return a==b;}

	Element Identity() const
		{return 0;}

	Element Add(Element a, Element b) const
		{return a^b;}

	Element& Accumulate(Element &a, Element b) const
		{return a^=b;}

	Element Inverse(Element a) const
		{return a;}

	Element Subtract(Element a, Element b) const
		{return a^b;}

	Element& Reduce(Element &a, Element b) const
		{return a^=b;}

	Element Double(Element a) const
		{CryptoPP_NV_2_UNUSED(a); return 0;}

	Element MultiplicativeIdentity() const
		{return 1;}

	Element Multiply(Element a, Element b) const;

	Element Square(Element a) const
		{return Multiply(a, a);}

	bool IsUnit(Element a) const
		{return a != 0;}

	Element MultiplicativeInverse(Element a) const;

	Element Divide(Element a, Element b) const
		{return Multiply(a, MultiplicativeInverse(b));}

private:
	word32 m_modulus;
};

NAMESPACE_END

#endif
