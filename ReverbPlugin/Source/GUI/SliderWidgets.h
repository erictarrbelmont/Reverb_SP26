/*
  ==============================================================================

    SliderWidgets.h
    Created: 24 Mar 2024 12:37:47pm
    Author:  Austin James

  ==============================================================================
*/

#pragma once

#include "../SharedImages.h"

class BigKnob : public juce::Slider
{
public:
    BigKnob(SharedImages* i) : knobImage(i->getBigKnob())
    {
//        setSize(488, 430);
        
        setTextBoxStyle (juce::Slider::NoTextBox, true, 0, 0);
        setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
        
    }
    
    
    ~BigKnob() {};
    
    void paint(juce::Graphics& g) override
    {
        
        const double fractRotation = (getValue() - getMinimum()) / (getMaximum() - getMinimum());
        
        int frameIdx = floor (fractRotation * (numFrames - 1));
        
        const int frameStartY = frameIdx * frameHeight;
        
//        int yPos = index * frameHeight;
        
        g.drawImage(knobImage, 0, 0, getWidth(), getHeight(), 0, frameStartY, 430, frameHeight);
        
    }
    
    
private:
    juce::Image& knobImage;
    
    int numFrames = 257;
    
    int frameHeight = 490;
};


class MediumKnob : public juce::Slider
{
public:
    MediumKnob(SharedImages* i) : knobImage(i->getMediumKnob())
    {
//        setSize(488, 430);
        
        setTextBoxStyle (juce::Slider::NoTextBox, true, 0, 0);
        setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
        
    }
    
    
    ~MediumKnob() {};
    
    void paint(juce::Graphics& g) override
    {
        
        const double fractRotation = (getValue() - getMinimum()) / (getMaximum() - getMinimum());
        
        int frameIdx = floor (fractRotation * (numFrames - 1));
        
        const int frameStartY = frameIdx * frameHeight;
        
//        int yPos = index * frameHeight;
        
        g.drawImage(knobImage, 0, 0, getWidth(), getHeight(), 0, frameStartY, 252, frameHeight);
        
    }
    
    
private:
    juce::Image& knobImage;
    
    int numFrames = 129;
    
    int frameHeight = 252;
};



class VertSlider : public juce::Slider
{
public:
    
    VertSlider(SharedImages* i) : sliderImage(i->getVertSlider())
    {
        
        setTextBoxStyle (juce::Slider::NoTextBox, true, 0, 0);
        setSliderStyle (juce::Slider::LinearBarVertical);

    }
    
    ~VertSlider(){};
    
    void paint(juce::Graphics& g) override
    {
        
        const double fractPosition = (getValue() - getMinimum()) / (getMaximum() - getMinimum());
        
        int frameIdx = floor (fractPosition * (numFrames - 1));
        
        const int frameStartY = frameIdx * frameHeight;
                
        g.drawImage(sliderImage, 0, 0, getWidth(), getHeight(), 0, frameStartY, frameWidth, frameHeight);
                
    }
    
    
    
    
private:
    juce::Image& sliderImage;
    
    int numFrames = 129;
    
    int frameHeight = 394;
      
    int frameWidth = 154;
    
};


class WheelSlider : public juce::Slider
{
public:
    
    WheelSlider(SharedImages* i) : sliderImage(i->getWheel())
    {
        
        setTextBoxStyle (juce::Slider::NoTextBox, true, 0, 0);
        setSliderStyle (juce::Slider::LinearBarVertical);
        
        setValue(5.0);
        
        
    }
    
    ~WheelSlider(){};
    
    void paint(juce::Graphics& g) override
    {
        
        const double fractPosition = (getValue() - getMinimum()) / (getMaximum() - getMinimum());
        
        int frameIdx = floor (fractPosition * (numFrames - 1));
        
        const int frameStartY = frameIdx * frameHeight;
        
        g.drawImage(sliderImage, 0, 0, getWidth(), getHeight(), 0, frameStartY, frameWidth, frameHeight);
        
    }
    
    
private:
    juce::Image& sliderImage;
    
    int numFrames = 129;
    
    int frameHeight = 406;
    
    int frameWidth = 160;
    
};
    
