// ***********************************************************************
//
// Demo program for education in subject
// Computer Architectures and Parallel Systems.
// Petr Olivka, dep. of Computer Science, FEI, VSB-TU Ostrava
// email:petr.olivka@vsb.cz
//
// Example of CUDA Technology Usage with unified memory.
//
// Image transformation from RGB to BW schema. 
// Image manipulation is performed by OpenCV library. 
//
// ***********************************************************************

#include <stdio.h>
#include <string.h>
#include <cuda_device_runtime_api.h>
#include <cuda_runtime.h>
#include "opencv2/opencv.hpp"
#include "pic_type.h"
#include "uni_mem_allocator.h"

using namespace cv;
#define 	CV_LOAD_IMAGE_COLOR 1
#define 	CV_AUTOSTEP  0x7fffffff

// Function prototype from .cu file
void cu_run_grayscale( CUDA_Pic bgr_pic, CUDA_Pic bw_pic );

int main( int numarg, char **arg )
{
	// Uniform Memory allocator for Mat
	UniformAllocator allocator;
	cv::Mat::setDefaultAllocator( &allocator );

	char filename[] = "goodpic.jpg";
	char filename2[] = "keny.jpg";
	//scanf("%s", &filename);
	// Load image
	Mat cv_bgr = imread( filename, CV_LOAD_IMAGE_COLOR );
	Mat cv_bgr2 = imread(filename2, CV_LOAD_IMAGE_COLOR);

	if ( !cv_bgr.data )
	{
		printf( "Unable to read file '%s'\n", filename );
		return 1;
	}

	// create empty BW image
	Mat cv_bw( cv_bgr.size(), CV_8U );
	Mat cv_resized(cv_bgr.size(), CV_8UC3);
	resize(cv_bgr, cv_resized, Size(), (double)cv_bgr2.size().width/cv_bgr.size().width,(double) cv_bgr2.size().height / cv_bgr.size().height, 3);
	imshow( "Color", cv_resized );

	 //data for CUDA
	CUDA_Pic pic_bgr, pic_bgr2, pic_bw;
	pic_bgr.Size.x = pic_bw.Size.x = cv_resized.size().width;
	pic_bgr.Size.y = pic_bw.Size.y = cv_resized.size().height;
	pic_bgr2.Size.x = cv_bgr2.size().width;
	pic_bgr2.Size.y = cv_bgr2.size().height;

	pic_bgr.P_uchar3 = ( uchar3 * ) cv_resized.data;
	pic_bgr2.P_uchar3 = (uchar3 *) cv_bgr2.data;
	pic_bw.P_uchar1 = ( uchar1 * ) cv_bw.data;

	// Function calling from .cu file
	cu_run_grayscale( pic_bgr, pic_bgr2);

	// Show the Color and BW image
	imshow( "Color", cv_resized);
	//imshow( "GrayScale", cv_resized);
	waitKey( 0 );
}

