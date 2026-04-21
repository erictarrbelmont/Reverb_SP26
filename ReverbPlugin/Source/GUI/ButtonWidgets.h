/*
  ==============================================================================

    ButtonWidgets.h
    Created: 24 Mar 2024 1:44:54pm
    Author:  Austin James

  ==============================================================================
*/

#pragma once
#include "../SharedImages.h"
class HitPads : public juce::ImageButton
{
public:
    HitPads(SharedImages* i) : buttonEnabled(i->getPadButtonOn()), buttonDisabled(i->getPadButtonOff())
    {
        setImages(true, false, true, buttonDisabled, 1.f, juce::Colours::transparentWhite, buttonDisabled, 1.f, juce::Colours::transparentWhite, buttonEnabled, 1.f, juce::Colours::transparentWhite);
        
    }
    
    ~HitPads() {};

    
private:
    juce::Image& buttonEnabled, buttonDisabled;
};
