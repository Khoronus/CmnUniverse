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

#include <algorithm>
#include <memory>

#include "ts/inc/ts/ts.hpp"
#include "cmnlibcore/inc/cmnlibcore/cmnlibcore_headers.hpp"
#include "string/inc/string/string_headers.hpp"

class ReportMessageGeneric : public CmnLib::core::Singleton<ReportMessageGeneric>
{
public:

	static ReportMessageGeneric& getSingleton(void);
	static ReportMessageGeneric* getSingletonPtr(void);

	virtual void report(const std::string &msg) = 0;

};
//-----------------------------------------------------------------------------
template<> ReportMessageGeneric* CmnLib::core::Singleton<ReportMessageGeneric>::ms_Singleton = 0;
ReportMessageGeneric* ReportMessageGeneric::getSingletonPtr(void)
{
	return ms_Singleton;
}
//-----------------------------------------------------------------------------
ReportMessageGeneric& ReportMessageGeneric::getSingleton(void)
{
	return *ms_Singleton;
}

class ReportMessageConsole : public ReportMessageGeneric
{
public:

	void report(const std::string &msg)
	{
		std::cout << "rmc: " << msg << std::endl;
	}
};

class ReportMessageLog : public ReportMessageGeneric
{
public:

	void report(const std::string &msg)
	{
		std::cout << "rml: " << msg << std::endl;
	}
};

// Unnamed namespace
namespace
{

/** Overload virtual method
*/
void test()	{
	std::unique_ptr<ReportMessageGeneric> rmg = std::unique_ptr<ReportMessageGeneric>(new ReportMessageConsole());

	rmg->getSingletonPtr()->report("ciao");
}

}  // namespace anonymous

CMNLIB_TEST_MAIN(&test, "MemoryLeakCPP.txt", "MemoryLeakC.txt");
