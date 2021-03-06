/* @file sample_control_logreporter.hpp
 * @brief Example of log file
 *
 * @section LICENSE
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR/AUTHORS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * @author  Unknwon
 * @modify Alessandro Moro <alessandromoro.italy@gmail.com>
 * @bug none
 * @version 1.1.1.0
 *
 */

#include "ts/inc/ts/ts.hpp"
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

	LogInformation("This is an information");
	LogAssert(0, "This is an assert");
	LogWarning("This is a warning");
	LogError("This is an error");
}

}  // namespace anonymous

CMNLIB_TEST_MAIN(&test, "MemoryLeakCPP.txt", "MemoryLeakC.txt");
//
//void main()
//{
//	test();
//}
