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

/** Overload virtual method
*/
void test()	{
	std::cout << "Example FileLog" << std::endl;
	CmnLib::control::Log log(std::string("SampleLog.txt"), 
		true);

	log.CreateFileHeader();
	log + std::string("This is a test");

	// It does not save and display messages from lower level than set one.
	std::cout << "Create LogMS: " << 
		CmnLib::control::LogMS::ResetLogFile("SampleLogMS.txt") << std::endl;
	CmnLib::control::LogMS::ResetLogLevel(CmnLib::control::LogLevel::Debug);
	CmnLib::control::LogMS::Debug("hello, come va?\n");
	CmnLib::control::LogMS::Info("hello, come va?\n");
	CmnLib::control::LogMS::Error("hello, come va?\n");
	CmnLib::control::LogMS::Fatal("hello, come va?\n");
}

}  // namespace anonymous

CMNLIB_TEST_MAIN(&test, "MemoryLeakCPP.txt", "MemoryLeakC.txt");
