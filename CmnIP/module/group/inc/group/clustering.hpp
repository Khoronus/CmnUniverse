/**
* @file clustering.hpp
* @brief Perform a phase correlation matching.
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
* @oauthor Alessandro Moro <alessandromoro.italy@gmail.com>
* @bug No known bugs.
* @version 0.1.0.0
*
*/


#ifndef CMNIP_GROUP_CLUSTERING_HPP__
#define CMNIP_GROUP_CLUSTERING_HPP__

#include <set>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <iterator>

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/calib3d/calib3d.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/features2d/features2d.hpp"

#include "opencv2/core/core.hpp"
//#include "opencv2/core/opengl_interop.hpp"
//#include "opencv2/contrib/contrib.hpp"

namespace CmnIP
{
namespace group
{

/** @brief Class to perform clustering operation on a set of points.

Class to perform clustering operation on a set of points.
*/
class Clustering
{
public:

	/** @brief k-mean clustering

	k-mean clustering. The cluster container memorize the index of the
	items associated together.
	@param[in] pts The set of points to cluster.
	@param[in] clusterCount The number of cluster expected. If greater
	than the number of points, it is reduced to the number of
	points.
	@param[out] cluster The container with the associated cluster points.
	@raturn Return 1 in case of success. 0 otherwise.
	*/
	static int kmean(const std::vector<cv::Point2f> &pts,
		int clusterCount,
		std::map<int, std::vector<int> > &cluster)
	{
		if (pts.size() == 0) return 0;

		int sampleCount = pts.size();
		cv::Mat points(sampleCount, 1, CV_32FC2), labels;

		clusterCount = MIN(clusterCount, sampleCount);
		cv::Mat centers(clusterCount, 1, points.type());

		/* generate random sample from multigaussian distribution */
		for (int k = 0; k < sampleCount; k++)
		{
			points.at<cv::Vec2f>(k, 0)[0] = pts[k].x;
			points.at<cv::Vec2f>(k, 0)[1] = pts[k].y;
		}

#if CV_MAJOR_VERSION == 3
		cv::kmeans(points, clusterCount, labels,
			cv::TermCriteria(CV_TERMCRIT_EPS + CV_TERMCRIT_ITER, 10, 1.0),
			3, cv::KMEANS_PP_CENTERS, centers);
#elif CV_MAJOR_VERSION == 4
		cv::kmeans(points, clusterCount, labels,
			cv::TermCriteria(cv::TermCriteria::EPS + cv::TermCriteria::MAX_ITER, 
				10, 1.0), 3, cv::KMEANS_PP_CENTERS, centers);
#endif

		std::map<int, cv::Scalar> colors;
		for (int i = 0; i < sampleCount; i++)
		{
			int clusterIdx = labels.at<int>(i);
			cluster[clusterIdx].push_back(i);
		}
		return 1;
	}

	/** @brief Cluster the points that are inside a centroid.

	Cluster the points that are inside a centroid. There is not optimization.
	It takes the first valid point and try to find all the points inside a
	centroid.
	@param[in] pts The set of points to cluster.
	@param[in] max_radius Max radius of the centroid.
	@param[out] cluster The container with the associated cluster points.
	@raturn Return 1 in case of success. 0 otherwise.
	*/
	static int set2cluster(const std::vector<cv::Point2f> &pts,
		float max_radius,
		std::map<int, std::vector<int> > &cluster)
	{
		if (pts.size() == 0) return 0;
		std::set<int> used;
		int clusterIdx = 0;
		for (size_t i = 0; i < pts.size(); i++)
		{
			if (used.find(i) == used.end())
			{
				cluster[clusterIdx].push_back(i);
				used.insert(i);
				for (size_t j = i + 1; j < pts.size(); j++)
				{
					if (used.find(j) == used.end())
					{
						float radius = std::sqrt(
							std::pow(pts[i].x - pts[j].x, 2) +
							std::pow(pts[i].y - pts[j].y, 2));
						if (radius < max_radius) {
							used.insert(j);
							cluster[clusterIdx].push_back(j);
						}
					}
				}
				++clusterIdx;
			}
		}
		return 1;
	}

};


} // namespace group
} // namespace CmnIP

#endif // CMNIP_GROUP_CLUSTERING_HPP__
