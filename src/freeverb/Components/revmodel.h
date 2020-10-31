// Reverb model declaration
//
// Written by Jezar at Dreampoint, June 2000
// http://www.dreampoint.co.uk
// This code is public domain

#ifndef _revmodel_
#define _revmodel_

#include "comb.h"
#include "allpass.h"
#include "tuning.h"

// enough for largest possible samplerate, 8 * 96000
const int maxsampleratio = 18;

class revmodel
{
public:
					revmodel(float sampleratio);
			void	mute();
			void	processmix(float *inputL, float *inputR, float *outputL, float *outputR, long numsamples, int skip);
			void	processreplace(float *inputL, float *inputR, float *outputL, float *outputR, long numsamples, int skip);
			void	setroomsize(float value);
			float	getroomsize();
			void	setdamp(float value);
			float	getdamp();
			void	setwet(float value);
			float	getwet();
			void	setdry(float value);
			float	getdry();
			void	setwidth(float value);
			float	getwidth();
			void	setmode(float value);
			float	getmode();
private:
			void	update();
private:
	float	gain;
	float	roomsize,roomsize1;
	float	damp,damp1;
	float	wet,wet1,wet2;
	float	dry;
	float	width;
	float	mode;

	// The following are all declared inline 
	// to remove the need for dynamic allocation
	// with its subsequent error-checking messiness

	// Comb filters
	comb	combL[numcombs];
	comb	combR[numcombs];

	// Allpass filters
	allpass	allpassL[numallpasses];
	allpass	allpassR[numallpasses];

	// Buffers for the combs
	float	bufcombL1[combtuningL1 * maxsampleratio];
	float	bufcombR1[combtuningR1 * maxsampleratio];
	float	bufcombL2[combtuningL2 * maxsampleratio];
	float	bufcombR2[combtuningR2 * maxsampleratio];
	float	bufcombL3[combtuningL3 * maxsampleratio];
	float	bufcombR3[combtuningR3 * maxsampleratio];
	float	bufcombL4[combtuningL4 * maxsampleratio];
	float	bufcombR4[combtuningR4 * maxsampleratio];
	float	bufcombL5[combtuningL5 * maxsampleratio];
	float	bufcombR5[combtuningR5 * maxsampleratio];
	float	bufcombL6[combtuningL6 * maxsampleratio];
	float	bufcombR6[combtuningR6 * maxsampleratio];
	float	bufcombL7[combtuningL7 * maxsampleratio];
	float	bufcombR7[combtuningR7 * maxsampleratio];
	float	bufcombL8[combtuningL8 * maxsampleratio];
	float	bufcombR8[combtuningR8 * maxsampleratio];

	// Buffers for the allpasses
	float	bufallpassL1[allpasstuningL1 * maxsampleratio];
	float	bufallpassR1[allpasstuningR1 * maxsampleratio];
	float	bufallpassL2[allpasstuningL2 * maxsampleratio];
	float	bufallpassR2[allpasstuningR2 * maxsampleratio];
	float	bufallpassL3[allpasstuningL3 * maxsampleratio];
	float	bufallpassR3[allpasstuningR3 * maxsampleratio];
	float	bufallpassL4[allpasstuningL4 * maxsampleratio];
	float	bufallpassR4[allpasstuningR4 * maxsampleratio];
};

#endif//_revmodel_

//ends
