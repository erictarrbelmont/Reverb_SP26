/*
  ==============================================================================

    AllPassFilter.cpp
    Created: 21 Apr 2026 1:14:14pm
    Author:  Tyler Ryan

  ==============================================================================
*/

#include "AllPassFilter.h"
AllPassFilter::AllPassFilter(float delay, float gain, float Fs){
    setDelay(delay);
    setGain(gain);
    setFs(Fs);
}

AllPassFilter::AllPassFilter(float delay, float gain, float Fs, float speed, float depth){
    setDelay(delay);
    setGain(gain);
    setFs(Fs);
    setSpeed(speed);
    setDepth(depth);
}
AllPassFilter::~AllPassFilter(){
    
}

void AllPassFilter::prepareToPlay(float delay, float gain){
    setDelay(delay);
    setGain(gain);
}

void AllPassFilter::prepareToPlay(float delay, float gain, float speed, float depth){
    setDelay(delay);
    setGain(gain);
    setSpeed(speed);
    setDepth(depth);
}

float AllPassFilter::getDelay(){
    return delay;
}
void AllPassFilter::setDelay(float delay){
    this->delay = delay;
    fracDelay.setDelaySamples((delay * 1000) / Fs);
}

float AllPassFilter::getGain(){
    return gain;
}
void AllPassFilter::setGain(float gain){
    this->gain = gain;
}

float AllPassFilter::getSpeed(){
    return speed;
}

void AllPassFilter::setSpeed(float speed){
    this->speed = speed;
    fracDelay.setSpeed(speed);
}

float AllPassFilter::getDepth(){
    return depth;
}

void AllPassFilter::setDepth(float depth){
    this->depth = depth;
    fracDelay.setDepth(depth);
}

float AllPassFilter::getFs(){
    return Fs;
}
void AllPassFilter::setFs(float Fs){
    this->Fs = Fs;
    fracDelay.setFs(Fs);
}


float AllPassFilter::processSample(float x, int channel){
    delayInput[channel] = x + delayOutput[channel];
    
    delayOutput[channel] = fracDelay.processSample(delayInput[channel], channel);
    
    return delayOutput[channel] + x * gain;
}
