// ***********************************************************************
//
// Demo program for education in subject
// Computer Architectures and Parallel Systems.
// Petr Olivka, dep. of Computer Science, FEI, VSB-TU Ostrava
// email:petr.olivka@vsb.cz
//
// Example of CUDA Technology Usage with unified memory.
//
// Image creation and its modification using CUDA.
// Image manipulation is performed by OpenCV library. 
//
// ***********************************************************************

#include <stdio.h>
#include <cuda_device_runtime_api.h>
#include <cuda_runtime.h>
#include "opencv2/opencv.hpp"
#include "pic_type.h"
#include "uni_mem_allocator.h"

using namespace cv;

// Prototype of function in .cu file
void cu_draw_flag( CUDA_Pic pic, uint2 block_size );

// Image size
#define SIZEX 500 // Width of image //576 tanzania, kuwait,600 velká británaaas
#define	SIZEY 334 // Height of image //384 tanzania, 288 kuwait, 300 velký vruntan
// Block size for threads
#define BLOCKX 40 // block width
#define BLOCKY 25 // block height


int main()
{

	// Creation of empty image.
	// Image is stored line by line.
	UniformAllocator allocator;
	cv::Mat::setDefaultAllocator(&allocator);

	Mat cv_img( SIZEY, SIZEX, CV_8UC3 );

	CUDA_Pic pic_img;
	pic_img.Size.x = cv_img.cols;
	pic_img.Size.y = cv_img.rows;
	pic_img.P_uchar3 = ( uchar3 * ) cv_img.data;

	// Function calling from .cu file
	uint2 block_size = { BLOCKX, BLOCKY };
	cu_draw_flag( pic_img, block_size ); 
	// Show modified image
	imshow( "Olympic flag", cv_img);
	waitKey( 0 );
}

