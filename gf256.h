// gf256.h - originally written and placed in the public domain by Wei Dai

/// \file gf256.h
/// \brief Classes and functions for schemes over GF(256)

#ifndef CryptoPP_NV_2_GF256_H
#define CryptoPP_NV_2_GF256_H

#include "cryptlib.h"
#include "misc.h"

NAMESPACE_BEGIN(CryptoPP_NV_2)

/// \brief GF(256) with polynomial basis
class GF256
{
public:
	typedef byte Element;
	typedef int RandomizationParameter;

	GF256(byte modulus) : m_modulus(modulus) {}

	Element RandomElement(RandomNumberGenerator &rng, int ignored = 0) const
		{CryptoPP_NV_2_UNUSED(ignored); return rng.GenerateByte();}

	bool Equal(Element a, Element b) const
		{return a==b;}

	Element Zero() const
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

	Element One() const
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
	word m_modulus;
};

NAMESPACE_END

#endif
