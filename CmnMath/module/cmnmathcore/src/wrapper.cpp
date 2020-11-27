// Geometric Tools LLC, Redmond WA 98052
// Copyright (c) 1998-2015
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
// File Version: 1.7.0 (2014/12/07)

#include "cmnmathcore/inc/cmnmathcore/wrapper.hpp"

namespace CmnMath
{
namespace core
{

//----------------------------------------------------------------------------
void Memcpy(void* target, void const* source, size_t count)
{
#if defined(WIN32)
    errno_t result = memcpy_s(target, count, source, count);
    (void)result;  // 0 on success
#else
    memcpy(target, source, count);
#endif
}
//----------------------------------------------------------------------------
void Memcpy(wchar_t* target, wchar_t const* source, size_t count)
{
#if defined(WIN32)
    errno_t result = wmemcpy_s(target, count, source, count);
    (void)result;  // 0 on success
#else
    wmemcpy(target, source, count);
#endif
}
//----------------------------------------------------------------------------

} // namespace core
} // namespace CmnMath
