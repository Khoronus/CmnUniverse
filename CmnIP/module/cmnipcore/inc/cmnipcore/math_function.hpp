/**
* @file math_function.hpp
* @brief Header of math functions (deprecated).
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
* @original author Alessandro Moro
* @bug No known bugs.
* @version 0.1.0.0
*
*/

#ifndef CMNIP_CMNIPCORE_MATHFUNCTION_HPP__
#define CMNIP_CMNIPCORE_MATHFUNCTION_HPP__

#include <cmath>

#if _MSC_VER && !__INTEL_COMPILER && (_MSC_VER > 1600)

#define CMNIP_LOG2F(v) std::log2f(v)
#define CMNIP_LOG2(v) std::log2(v)

#else

#define CMNIP_LOG2F(v) std::log(v)
#define CMNIP_LOG2(v) std::log(v)

#endif

#endif // CMNIP_CMNIPCORE_MATHFUNCTION_HPP__
