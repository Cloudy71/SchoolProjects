// ***********************************************************************
//
// Demo program for education in subject
// Computer Architectures and Paralel Systems.
// Petr Olivka, dep. of Computer Science, FEI, VSB-TU Ostrava
// email:petr.olivka@vsb.cz
//
// Example of CUDA Technology Usage with unified memory.
//
// Manipulation with prepared image.
//
// ***********************************************************************

#include <cuda_device_runtime_api.h>
#include <cuda_runtime.h>
#include <stdio.h>
#include <math.h>
#include "pic_type.h"

// Every threads identifies its position in grid and in block and modify image
__global__ void kernel_animation(CUDA_Pic cuda_pic)
{
	// X,Y coordinates 
	int y = blockDim.y * blockIdx.y + threadIdx.y;
	int x = blockDim.x * blockIdx.x + threadIdx.x;
	if (x >= cuda_pic.Size.x) return;
	if (y >= cuda_pic.Size.y) return;
	uint2 xy[5] = { {125,130}, {250,130}, {375,130}, {190,190}, {315,190} };
	int outerRadius = 60;
	int innerRadius = 52;
	uchar3 bgr;

	//tanzania
	/*if (x<=(cuda_pic.Size.y-y)*1.5)
		bgr = { 58,181,30 };
	else
		bgr = {221,163,0};

	if ((x <= ((cuda_pic.Size.y - y)*1.5)+76) && (x > ((cuda_pic.Size.y - y)*1.5) - 76))
		bgr = { 22,209,252 };

	if ((x <= ((cuda_pic.Size.y - y)*1.5) + 52) && (x > ((cuda_pic.Size.y - y)*1.5) - 52))
		bgr = { 0,0,0 };*/

		//kuwait
		/*if (y < cuda_pic.Size.y / 3)
			bgr = { 61,122,0 };
		else if (y <= 2 * cuda_pic.Size.y / 3 && y >= cuda_pic.Size.y / 3)
			bgr = { 255,255,255 };
		else
			bgr = { 38,17,206 };

		if ((x <= y*1.5 && y < cuda_pic.Size.y / 3) || (x <= (cuda_pic.Size.y - y) * 1.5 && y > 2*cuda_pic.Size.y / 3)
			|| (x<=cuda_pic.Size.x/4 && y>= cuda_pic.Size.y / 3 && y <= 2 * cuda_pic.Size.y / 3))
			bgr = { 0,0,0 };*/

			//Great Britain
			/*bgr = { 125,36,0 };
			if ((x > cuda_pic.Size.x / 2 - 50 && x < cuda_pic.Size.x / 2 + 50) || (y > cuda_pic.Size.y / 2 - 50 && y < cuda_pic.Size.y / 2 + 50)
				 || (x <= ((cuda_pic.Size.y - y)*2.) + 60) && (x > ((cuda_pic.Size.y - y)*2.) - 60)
				 || (x <= ((y*2.) + 60) && (x > (y*2.) - 60)))
				bgr = { 255,255,255 };
			if ((x > cuda_pic.Size.x / 2 - 30 && x < cuda_pic.Size.x / 2 + 30) || (y > cuda_pic.Size.y / 2 - 30 && y < cuda_pic.Size.y / 2 + 30)
				|| (x <= ((cuda_pic.Size.y - y)*2.)) && (x >((cuda_pic.Size.y - y)*2.) - 40)
				|| (x <= ((y*2.)) && (x > (y*2.) - 40)))
				bgr = {43,20,207};*/

	bgr = { 255,255,255 };

	if ((outerRadius*outerRadius > (xy[0].x - x)*(xy[0].x - x) + (xy[0].y - y)*(xy[0].y - y)) && (innerRadius*innerRadius < (xy[0].x - x)*(xy[0].x - x) + (xy[0].y - y)*(xy[0].y - y)))
		bgr = { 199,133,0 };
	else if ((outerRadius*outerRadius >(xy[1].x - x)*(xy[1].x - x) + (xy[1].y - y)*(xy[1].y - y)) && (innerRadius*innerRadius < (xy[1].x - x)*(xy[1].x - x) + (xy[1].y - y)*(xy[1].y - y)))
		bgr = { 0,0,0 };
	else if ((outerRadius*outerRadius >(xy[2].x - x)*(xy[2].x - x) + (xy[2].y - y)*(xy[2].y - y)) && (innerRadius*innerRadius < (xy[2].x - x)*(xy[2].x - x) + (xy[2].y - y)*(xy[2].y - y)))
		bgr = { 36,0,223 };
	else if ((outerRadius*outerRadius >(xy[3].x - x)*(xy[3].x - x) + (xy[3].y - y)*(xy[3].y - y)) && (innerRadius*innerRadius < (xy[3].x - x)*(xy[3].x - x) + (xy[3].y - y)*(xy[3].y - y)))
		bgr = { 0,195,244 };
	else if ((outerRadius*outerRadius >(xy[4].x - x)*(xy[4].x - x) + (xy[4].y - y)*(xy[4].y - y)) && (innerRadius*innerRadius < (xy[4].x - x)*(xy[4].x - x) + (xy[4].y - y)*(xy[4].y - y)))
		bgr = { 61,159,0 };
	

	cuda_pic.P_uchar3[ y * cuda_pic.Size.x + x ] = bgr;
}

void cu_draw_flag( CUDA_Pic pic, uint2 block_size )
{
	cudaError_t cerr;

	// Grid creation with computed organization
	dim3 grid( ( pic.Size.x + block_size.x - 1 ) / block_size.x, ( pic.Size.y + block_size.y - 1 ) / block_size.y );
	kernel_animation<<< grid, dim3( block_size.x, block_size.y ) >>>( pic );

	if ( ( cerr = cudaGetLastError() ) != cudaSuccess )
		printf( "CUDA Error [%d] - '%s'\n", __LINE__, cudaGetErrorString( cerr ) );

	cudaDeviceSynchronize();

}
