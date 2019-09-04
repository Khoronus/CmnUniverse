/**

THERE IS NO WARRANTY FOR THE PROGRAM, TO THE EXTENT PERMITTED BY 
APPLICABLE LAW. EXCEPT WHEN OTHERWISE STATED IN WRITING THE 
COPYRIGHT HOLDERS AND/OR OTHER PARTIES PROVIDE THE PROGRAM 
�gAS IS�h WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESSED OR 
IMPLIED, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES 
OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. 
THE ENTIRE RISK AS TO THE QUALITY AND PERFORMANCE OF THE PROGRAM 
IS WITH YOU. SHOULD THE PROGRAM PROVE DEFECTIVE, YOU ASSUME THE 
COST OF ALL NECESSARY SERVICING, REPAIR OR CORRECTION.

*/

#ifndef CMNMATH_CMNMATHCORE_LIBDEFINE_HPP__
#define CMNMATH_CMNMATHCORE_LIBDEFINE_HPP__

/*
	Define if use the OpenCV code
*/
#define COMPILE_WITH_OPENCV 1

#if COMPILE_WITH_OPENCV == 1
#define USE_OPENCV
#endif

/*
	Define if use the CmnLib library
*/
#define COMPILE_WITH_CMNLIB 1

#if COMPILE_WITH_CMNLIB == 1
#define USE_CMNLIB
#endif


#endif /* CMNMATH_CMNMATHCORE_LIBDEFINE_HPP__ */
