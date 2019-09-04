/**

THERE IS NO WARRANTY FOR THE PROGRAM, TO THE EXTENT PERMITTED BY 
APPLICABLE LAW. EXCEPT WHEN OTHERWISE STATED IN WRITING THE 
COPYRIGHT HOLDERS AND/OR OTHER PARTIES PROVIDE THE PROGRAM 
“AS IS” WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESSED OR 
IMPLIED, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES 
OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. 
THE ENTIRE RISK AS TO THE QUALITY AND PERFORMANCE OF THE PROGRAM 
IS WITH YOU. SHOULD THE PROGRAM PROVE DEFECTIVE, YOU ASSUME THE 
COST OF ALL NECESSARY SERVICING, REPAIR OR CORRECTION.

*/

#ifndef CMNLIB_STRING_STRINGCONVERSION_HPP__
#define CMNLIB_STRING_STRINGCONVERSION_HPP__

#include <iostream>
#include <sstream>
#include <string>

namespace CmnLib
{
namespace text
{


/** @brief Class to convert string and numbers
*/
class StringConversion
{
public:

	/** @brief Function to conver number to string.

	Function to conver number to string.
	@param[in] Number to convert.
	@return Return the string.
	@code

	NumberToString ( Number );

	@endcode
	*/
	template <typename T>
	static std::string NumberToString(T Number)
	{
		std::ostringstream ss;
		ss << Number;
		return ss.str();
	}

	/** @brief Function to conver string to number.

	Function to conver string to number.
	@param[in] String to convert.
	@return Return the number.
	@code

	StringToNumber<Type> ( String )

	@endcode
	*/
	template <typename T>
	static T StringToNumber(const std::string &Text)
	{
		std::istringstream ss(Text);
		T result;
		return ss >> result ? result : 0;
	}
};


} // namespace text
} // namespace CmnLib

#endif