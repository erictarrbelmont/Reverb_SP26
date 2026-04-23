/*
  ==============================================================================

    FeedbackCombFilter.cpp
    Created: 21 Apr 2026 1:21:04pm
    Author:  Student User

  ==============================================================================
*/

#include "FeedbackCombFilter.h"

FeedbackCombFilter::FeedbackCombFilter(float ms, float sampleRate, float speed = 1.f, float depth = 10.f);

float FeedbackCombFilter::processSample(float x, int channel){
   fractionalDelay.processSample(x,chaneel);
    
}

void FeedbackCombFilter::setFs(float sampleRate){
    //updating delay value to new sampleRate
    delay *= sampleRate/Fs;
    
    fractionalDelay.setFs(sampleRate);
    Fs = sampleRate;
    
}

void FeedbackCombFilter::setGain(float g){
    gain = g;
}

void FeedbackCombFilter::setDelayMs(float ms){
    delay = (ms/1000) * Fs;
}


void FeedbackCombFilter::setSpeed(float s){
	fractionalDelay.setSpeed(s);	
}
void FeedbackCombFilter::setDepth(float d){
	fractionalDelay.setDepth(d);
}
