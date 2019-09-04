// Geometric Tools LLC, Redmond WA 98052
// Copyright (c) 1998-2015
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
// File Version: 1.0.0 (2014/08/11)

#include "control\inc\control\LogToStringArray.hpp"

namespace CmnLib
{
namespace control
{

//----------------------------------------------------------------------------
LogToStringArray::LogToStringArray(std::string const& name, int flags)
    :
    Logger::Listener(flags),
    mName(name)
{
}
//----------------------------------------------------------------------------
std::string const& LogToStringArray::GetName() const
{
    return mName;
}
//----------------------------------------------------------------------------
std::vector<std::string> const& LogToStringArray::GetMessages() const
{
    return mMessages;
}
//----------------------------------------------------------------------------
std::vector<std::string>& LogToStringArray::GetMessages()
{
    return mMessages;
}
//----------------------------------------------------------------------------
void LogToStringArray::Report(std::string const& message)
{
    mMessages.push_back(message);
}
//----------------------------------------------------------------------------
}  // namespace control
}  // namespace CmnLib
