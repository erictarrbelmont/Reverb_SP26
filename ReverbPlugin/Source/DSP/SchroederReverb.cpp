/*
  ==============================================================================

    SchroederReverb.cpp
    Created: 21 Apr 2026 1:29:20pm
    Author:  Jack Dunn

  ==============================================================================
*/

#include "SchroederReverb.h"

void SchroederReverb::setReverbLength(float ms, int channel) {
	
	reverbTime.setTargetValue(ms);
		
}

void SchroederReverb::setReverbDensity(float density, int channel) {
	
	reverbDensity.setTargetValue(density);

}

void SchroederReverb::setWowRate(float wowRateHz) {

	fbcf1.setWowRate(wowRateHz);
	fbcf2.setWowRate(wowRateHz);
	fbcf3.setWowRate(wowRateHz);
	fbcf4.setWowRate(wowRateHz);
}

void SchroederReverb::setWowDepth(float wowDepth) {

	fbcf1.setWowDepth(wowDepth);
	fbcf2.setWowDepth(wowDepth);
	fbcf3.setWowDepth(wowDepth);
	fbcf4.setWowDepth(wowDepth);
}

void SchroederReverb::prepareToPlay(juce::dsp::ProcessSpec& spec) {

	sampleRate = spec.sampleRate;
	fbcf1.prepareToPlay(sampleRate);
	fbcf2.prepareToPlay(sampleRate);
	fbcf3.prepareToPlay(sampleRate);
	fbcf4.prepareToPlay(sampleRate);
	apff1.prepareToPlay(sampleRate);
	apff2.prepareToPlay(sampleRate);
	
	fbcf1.setDelayMs(DEFAULT_FBCF1_DELAY_MS);
	fbcf2.setDelayMs(DEFAULT_FBCF2_DELAY_MS);
	fbcf3.setDelayMs(DEFAULT_FBCF3_DELAY_MS);
	fbcf4.setDelayMs(DEFAULT_FBCF4_DELAY_MS);

	apf1.setDelayMs(DEFAULT_APF1_DELAY_MS);
	apf2.setDelayMs(DEFAULT_APF2_DELAY_MS);

}

void SchroederReverb::processBuffer(float* buffer, int channel, int bufferSize) {
	for (int n = 0; n < bufferSize) {
		buffer[n] = processSample(buffer[n], channel);
	}
}

float SchroederReverb::processSample(float x, int channel) {

	fbcf1.setDelayMs(reverbTime.getNextValue());
	fbcf2.setDelayMs(reverbTime.getNextValue());
	fbcf3.setDelayMs(reverbTime.getNextValue());
	fbcf4.setDelayMs(reverbTime.getNextValue());

	apf1.setDelayMs(reverbTime.getNextValue());
	apf2.setDelayMs(reverbTime.getNextValue());

	float fbcfOut = fbcf1.processSample(x) + fbcf2.processSample(x) + fbcf3.processSample(x) + fbcf4.processSample(x);
	
	float apf1Out = apf1.processSample(fbcfOut);
	float apf2Out = apf2.processSample(apf1Out);
	
	return apf2Out;

}
