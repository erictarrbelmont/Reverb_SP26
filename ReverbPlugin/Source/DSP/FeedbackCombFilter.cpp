/*
  ==============================================================================

    FeedbackCombFilter.cpp
    Created: 21 Apr 2026 1:21:04pm
    Author:  Student User

  ==============================================================================
*/

#include "FeedbackCombFilter.h"

float FeedbackCombFilter::processSample(float x, int channel){
   return fractionalDelay.processSample(x,channel) * this->gain;
    
}

void FeedbackCombFilter::setFs(float sampleRate){    
    
    fractionalDelay.setFs(sampleRate);
    Fs = sampleRate;

    //updating delay value to new sampleRate
    FeedbackCombFilter::setDelayMs(this->delayMs);    
    
}

void FeedbackCombFilter::setGain(float g){
    this->gain = g;
}

void FeedbackCombFilter::setDelayMs(float ms){
    float delaySamples = this->delayMs * Fs;
    fractionalDelay.setDelaySamples(this->delay);  
}

void FeedbackCombFilter::setSpeed(float s){
	fractionalDelay.setSpeed(s);	
}

void FeedbackCombFilter::setDepth(float d){
	fractionalDelay.setDepth(d);
}
