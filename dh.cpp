// dh.cpp - originally written and placed in the public domain by Wei Dai

#include "pch.h"

#ifndef CryptoPP_NV_2_IMPORTS

#include "dh.h"

NAMESPACE_BEGIN(CryptoPP_NV_2)

#if defined(CryptoPP_NV_2_DEBUG) && !defined(CryptoPP_NV_2_DOXYGEN_PROCESSING)
void DH_TestInstantiations()
{
	DH dh1;
	DH dh2(NullRNG(), 10);
}
#endif

NAMESPACE_END

#endif
