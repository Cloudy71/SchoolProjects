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
//
// ***********************************************************************

#include <stdio.h>
#include <cuda_device_runtime_api.h>
#include <cuda_runtime.h>
#include "pic_type.h"

// Demo kernel to transform RGB color schema to BW schema
__global__ void kernel_grayscale( CUDA_Pic colorPic, CUDA_Pic colorPic2 )
{
	// X,Y coordinates and check image dimensions
	int y = blockDim.y * blockIdx.y + threadIdx.y;
	int x = blockDim.x * blockIdx.x + threadIdx.x;
	if ( y >= colorPic.Size.y ) return;
	if ( x >= colorPic.Size.x ) return;

	// Get point from color picture
	uchar3 bgr = ( x < y*(colorPic.Size.y/ colorPic.Size.x)) ? colorPic.P_uchar3[ y * colorPic.Size.x + x ] : colorPic2.P_uchar3[y * colorPic.Size.x + x];
	printf("B=%d, G=%d, R=%d\n", bgr.x, bgr.y, bgr.z);

	// Store BW point to new image
	colorPic.P_uchar3[y * colorPic.Size.x + x] = bgr;
}

void cu_run_grayscale( CUDA_Pic colorPic, CUDA_Pic colorPic2)
{
	cudaError_t cerr;

	// Grid creation, size of grid must be equal or greater than images
	int block_size = 16;
	dim3 blocks( ( colorPic.Size.x + block_size - 1 ) / block_size, ( colorPic.Size.y + block_size - 1 ) / block_size );
	dim3 threads( block_size, block_size );
	kernel_grayscale<<< blocks, threads >>>( colorPic, colorPic2);

	if ( ( cerr = cudaGetLastError() ) != cudaSuccess )
		printf( "CUDA Error [%d] - '%s'\n", __LINE__, cudaGetErrorString( cerr ) );
	cudaDeviceSynchronize();
}
