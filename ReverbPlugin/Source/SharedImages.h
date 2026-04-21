/*
  ==============================================================================

    SharedImages.h
    Created: 24 Mar 2024 11:10:15am
    Author:  Austin James

  ==============================================================================
*/

#pragma once
#include "StandardIncludes.h"

class SharedImages {

public:
    
    SharedImages(){ loadImages(); };
    
    void loadImages();
    
    juce::Image& getBackgroundImage() { return m_BackgroundImage; };
    
    juce::Image& getBigKnob()         { return m_BigKnob; };
    
    juce::Image& getMediumKnob()      { return m_MediumKnob; };
    
    juce::Image& getVertSlider()      { return m_VertSlider; };
    
    juce::Image& getHorzSlider()      {return m_HorzSlider; };
    
    juce::Image& getPadButtonOn()     { return m_PadButtonOn; };
    
    juce::Image& getPadButtonOff()    { return m_PadButtonOff; };
    
    juce::Image& getSwitchUp()        { return m_SwitchUp; };
    
    juce::Image& getSwitchDown()      { return m_SwitchDown; };
    
    juce::Image& getVUMeter()         { return m_VUMeter; };
    
    juce::Image& getWheel()           { return m_Wheel; };
    
    
private:
    
    juce::Image m_BackgroundImage;
    
    juce::Image m_BigKnob;
    
    juce::Image m_MediumKnob;
    
    juce::Image m_VertSlider;
    
    juce::Image m_HorzSlider;
    
    juce::Image m_PadButtonOn;
    
    juce::Image m_PadButtonOff;
    
    juce::Image m_SwitchUp;
    
    juce::Image m_SwitchDown;
    
    juce::Image m_VUMeter;
    
    juce::Image m_Wheel;
    
    
    
};
