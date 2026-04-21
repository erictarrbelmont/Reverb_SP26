/*
  ==============================================================================

    MeterWidget.h
    Created: 3 Apr 2024 7:38:42pm
    Author:  Austin James

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "../PluginProcessor.h"
#include "../SharedImages.h"

class VUMeter : public juce::Component, private juce::Timer
{
public:
    VUMeter(ReverbPluginAudioProcessor& p) :
        sharedImages(p.getSharedImages()),
        audioProcessor(p),
        vuMeter(sharedImages->getVUMeter())
    {
        
        startTimerHz(30);
        
    }
    
    ~VUMeter(){}
    
    void paint(juce::Graphics& g) override
    {
        // intended size is frameWidth x frameHeight
        auto frameStartY = index * frameHeight;
        
        if (frameStartY > maxFramePosition) // Makes sure doesn't grab out of bounds position
            frameStartY = maxFramePosition;
        
//        if (frameStartY < 0)
//            frameStartY = 0;
        
//        DBG("Frame Start Y Pos: " + juce::String(frameStartY));
        
        g.drawImage(vuMeter, 0, 0, getWidth(), getHeight(), 0, frameStartY, frameWidth, frameHeight);
        
    }
    
    void timerCallback() override {
        
        updateMeter();

        repaint();
    }
    
    void updateMeter()
    {
        
        float linLevel = audioProcessor.getOutputLevel (true); // linear amp
        float dbLevel = juce::Decibels::gainToDecibels (linLevel, -100.f);

//        DBG("DB Level: " + juce::String(dbLevel));
        
        index = floor(juce::jmap(dbLevel, -100.f, 0.f, 0.f, numFrames)); // Mapping level from 0 to size of image array
          
        repaint();
    }
    
    
    
private:
    SharedImages* sharedImages;
    ReverbPluginAudioProcessor& audioProcessor;
        
    juce::Image& vuMeter;
    
    int frame = 0;
    
    float numFrames = 129.f;
    
    int frameHeight = 280;
    
    int frameWidth = 536;

    int index = 0;
    
    int maxFramePosition = (int)(frameHeight * 129);
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (VUMeter)
};

class SimpleMeter : public juce::Component, private juce::Timer
{
public:
    SimpleMeter(ReverbPluginAudioProcessor& p) :
        audioProcessor(p)
    {
        
        startTimerHz(30);
        
    }
    
    ~SimpleMeter(){}
    
    void paint(juce::Graphics& g) override
    {
        auto bounds = getLocalBounds().toFloat().reduced(3.f);

        g.setColour(juce::Colours::black);
        g.fillRect(bounds);

        g.setGradientFill(gradient);
        const auto scaledY = juce::jmap(dbLevel, -60.f, 6.f, 0.f, static_cast<float>(getHeight()));
        g.fillRect(bounds.removeFromBottom(scaledY));
    }

    void resized() override
    {
        const auto bounds = getLocalBounds().toFloat();
        gradient = juce::ColourGradient{ juce::Colours::green, bounds.getBottomLeft(), juce::Colours::red, bounds.getTopLeft(), false };
        gradient.addColour(0.5, juce::Colours::yellow);
    }
    
    
    void timerCallback() override {
        
        updateMeter();

        repaint();
    }
    
    void updateMeter()
    {
        
        float linLevel = audioProcessor.getOutputLevel (true); // linear amp
        dbLevel = juce::Decibels::gainToDecibels (linLevel, -100.f);

//        DBG("DB Level: " + juce::String(dbLevel));
        
//        mappedValue = juce::jmap(dbLevel, -100.f, 0.f, 0.f, numFrames); // Mapping level from 0 to size of image array
          
        repaint();
    }
    
    
    
private:
    ReverbPluginAudioProcessor& audioProcessor;
            
    juce::ColourGradient gradient{};
    
    float dbLevel = 0;
    
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SimpleMeter)
};
