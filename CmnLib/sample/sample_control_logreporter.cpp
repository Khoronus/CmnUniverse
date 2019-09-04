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

#include "ts\inc\ts\ts.hpp"
#include "cmnlibcore/inc/cmnlibcore/cmnlibcore_headers.hpp"
#include "control/inc/control/control_headers.hpp"

// Unnamed namespace
namespace
{

/** Examlpe logreport
*/
void test()	{
	std::cout << "Example LogReport" << std::endl;
	CmnLib::control::LogReporter reporter(
		"LogReport.txt",
		CmnLib::control::Logger::Listener::LISTEN_FOR_ALL,
		CmnLib::control::Logger::Listener::LISTEN_FOR_ALL,
		CmnLib::control::Logger::Listener::LISTEN_FOR_ALL,
		CmnLib::control::Logger::Listener::LISTEN_FOR_ALL);

	LogWarning("This is a warning");
	LogError("This is an error");
	LogInformation("This is an information");
	LogAssert(0, "This is an assert");
}

}  // namespace anonymous

CMNLIB_TEST_MAIN(&test, "MemoryLeakCPP.txt", "MemoryLeakC.txt");
//
//void main()
//{
//	test();
//}
