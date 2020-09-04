/**
* @file distance_threedim_sphere.hpp
* @brief Header
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
* @version 0.1.1.0
*
*/

#ifndef CMNMATH_GEOMETRY_DISTANCETHREEDIMSPHERE_HPP__
#define CMNMATH_GEOMETRY_DISTANCETHREEDIMSPHERE_HPP__

#include <cmath>

namespace CmnMath
{
namespace geometry
{

template <typename _Ty3D, typename REAL>
class distance_threedim_sphere
{
public:

	/** @brief Estimate distance
	*/
	static REAL spherical_law_cosines(const _Ty3D &p, const _Ty3D &q, REAL r) {
		return r * std::acos(std::sin(p[2]) * std::sin(q[2]) +
			std::cos(p[2]) * std::cos(p[2]) * std::cos(std::abs(p[1] - q[1])));
	}
};

} // namespace geometry
} // namespace CmnMath

#endif // CMNMATH_GEOMETRY_DISTANCETHREEDIMSPHERE_HPP__
