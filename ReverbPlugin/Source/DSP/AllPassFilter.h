/*
  ==============================================================================

    AllPassFilter.h
    Created: 21 Apr 2026 1:14:14pm
    Author:  Tyler Ryan

  ==============================================================================
*/

#pragma once
#include "FractionalDelay.hpp"

class AllPassFilter{
    public:
    
    AllPassFilter(float delay, float gain, float Fs);
    AllPassFilter(float delay, float gain, float Fs, float speed, float depth);
    ~AllPassFilter();
    
    void prepareToPlay(float delay, float gain, float Fs);
    void prepareToPlay(float delay, float gain, float Fs, float speed, float depth);
    
    float getDelay();
    void setDelay(float delay);
    
    float getGain();
    void setGain(float gain);
    
    float getFs();
    void setFs(float Fs);
    
    float getSpeed();
    void setSpeed(float speed);
    
    float getDepth();
    void setDepth(float depth);
    
    float processSample(float x, int channe);
    
    
    private:
    
    FractionalDelay fracDelay;
    float delayOutput[2] = {0.0f};
    float delayInput[2] = {0.0f};
    float delay; //Ms
    float gain; //0-1
    float Fs;
    float speed; // Hz, frequency of LFO
    float depth; // percentage of intensity, control amp of LFO
    
};
