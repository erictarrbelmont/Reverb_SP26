/*
  ==============================================================================

    SchroederReverb.h
    Created: 21 Apr 2026 1:29:20pm
    Author:  Jack Dunn

  ==============================================================================
*/

#pragma once
#include "JuceHeader.h"
#include "FeedbackCombFilter.h"
#include "AllPassFilter.h"

using SVFL = juce::SmoothedValue<float, juce::ValueSmoothingTypes::Linear>;

class SchroederReverb {
	private:
	float sampleRate = 48000;
	SVFL reverbTime = 200.f;
	SVFL reverbDensity = 0.5f;
	
	FeedbackCombFilter fbcf1, fbcf2, fbcf3, fbcf4;
	
	const float DEFAULT_FBCF1_DELAY_MS = 59.f;
	const float DEFAULT_FBCF2_DELAY_MS = 74.2f;
	const float DEFAULT_FBCF3_DELAY_MS = 82.2f;
	const float DEFAULT_FBCF4_DELAY_MS = 87.4f;

	
	AllPassFilter apf1, apf2;
	
	const float DEFAULT_APF1_DELAY_MS = 0.01f;
	const float DEFAULT_APF2_DELAY_MS = 3.4f;

	public:

	void setReverbLength(float ms, int channel);
	void setReverbDensity(float density, int channel);
	void setWowRate(float wowRateHz);
	void setWowDepth(float wowDepth);
	void prepareToPlay(juce::dsp::ProcessSpec& spec);
	void processBuffer(float* buffer, int channel, int bufferSize);
	float processSample(float x, int channel);

	
};
