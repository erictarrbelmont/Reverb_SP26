/*
  ==============================================================================

    FeedbackCombFilter.h
    Created: 21 Apr 2026 1:21:04pm
    Author:  Student User

  ==============================================================================
*/

#pragma once
#include "FractionalDelay.hpp"

class FeedbackCombFilter
{
    public:
    
    FeedbackCombFilter();
	FeedbackCombFilter(float ms, float sampleRate, float speed = 1.f, float depth = 10.f);
    
    //destructor
    ~FeedbackCombFilter();
    
    float processSample(float x, int channel);

    void setFs(float sampleRate);
    
    void setGain(float g);
    
    void setDelayMs(float ms);

	void setSpeed(float s);
	void setDepth(float d);
 
    
//    void setSpeed(float speed);
//    void setDepth(float depth);

    
private:
    
    float Fs = 48000.f;
    
    float delay = 5.f;
    
    float gain;
//    
//    const int MAX_BUFFER_SIZE = 96000;
//    float delayBuffer[96000][2] = {0.0f};
//    int index[2] = {0};
    
    FractionalDelay fractionalDelay;
    
//    float speed = 1.0f; // Hz, frequency of LFO
//    float depth = 10.0f; // percentage of intensity, control amp of LFO
    
//    float currentAngle[2] = {0.0f};
//    float angleChange = speed * (1.f/Fs) * 2.f * M_PI;
    
    
};
