/*
  ==============================================================================

    SchroederReverb.cpp
    Created: 21 Apr 2026 1:29:20pm
    Author:  Jack Dunn

  ==============================================================================
*/

#include "SchroederReverb.h"

void SchroederReverb::setReverbLength(float ms, int channel) {
	
}

void SchroederReverb::setReverbDensity(float density, int channel) {
	
}

void SchroederReverb::setWowRate(float wowRateHz) {
	
}

void SchroederReverb::setWowDepth(float wowDepth) {
	
}

void SchroederReverb::prepareToPlay(juce::dsp::ProcessSpec& spec) {
	sampleRate = spec.sampleRate;
	fbcf1.prepareToPlay(sampleRate);
	fbcf2.prepareToPlay(sampleRate);
	fbcf3.prepareToPlay(sampleRate);
	fbcf4.prepareToPlay(sampleRate);
	apff1.prepareToPlay(sampleRate);
	apff2.prepareToPlay(sampleRate);
}

void SchroederReverb::processBuffer(float* buffer, int channel, int bufferSize) {
	for (int n = 0; n < bufferSize) {
		buffer[n] = processSample(buffer[n], channel);
	}
}

float SchroederReverb::processSample(float x, int channel) {
	
	float fbcfOut = fbcf1.processSample(x) + fbcf2.processSample(x) + fbcf3.processSample(x) + fbcf4.processSample(x);
	
	float apf1Out = apf1.processSample(fbcfOut);
	float apf2Out = apf2.processSample(apf1Out);
	
	return apf2Out;

}
