/**
* @file matrixoperation.hpp
* @brief Class to perform some operations with matrix
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
* @original author Will Perone (will.perone@gmail.com)
* @modified by Alessandro Moro
* @bug No known bugs.
* @version 0.1.0.0
*
*/

#ifndef CMNMATH_ALGEBRALINEAR_SHRINK_HPP__
#define CMNMATH_ALGEBRALINEAR_SHRINK_HPP__

#include <memory>
#include <cmath>

namespace CmnMath
{
namespace algebralinear
{

/** @brief Class to calculate the shrinking of a value.

    Class to calculate the shrinking of a value.
*/
class Shrink
{
public:
	//--------------------------------
	// signum
	//--------------------------------
	static CMN_32F sgn(CMN_32F x)
	{
		CMN_32F res = 0;
		if (x == 0)
		{
			res = 0;
		}
		if (x>0)
		{
			res = 1;
		}
		if (x<0)
		{
			res = -1;
		}
		return res;
	}
	//--------------------------------
	// Soft shrinkage
	//--------------------------------
	static CMN_32F soft(CMN_32F d, CMN_32F T)
	{
		CMN_32F res;
		if (fabs(d)>T)
		{
			res = sgn(d)*(fabs(d) - T);
		}
		else
		{
			res = 0;
		}

		return res;
	}
	//--------------------------------
	// Hard shrinkage
	//--------------------------------
	static CMN_32F hard(CMN_32F d, CMN_32F T)
	{
		CMN_32F res;
		if (fabs(d)>T)
		{
			res = d;
		}
		else
		{
			res = 0;
		}

		return res;
	}
	//--------------------------------
	// Garrot shrinkage
	//--------------------------------
	static CMN_32F Garrot(CMN_32F d, CMN_32F T)
	{
		CMN_32F res;
		if (fabs(d)>T)
		{
			res = d - ((T*T) / d);
		}
		else
		{
			res = 0;
		}

		return res;
	}
};



} // namespace algebralinear
} // namespace CmnMath

#endif /* CMNMATH_ALGEBRALINEAR_SHRINK_HPP__ */
