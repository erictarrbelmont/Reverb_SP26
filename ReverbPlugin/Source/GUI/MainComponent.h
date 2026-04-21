/*
  ==============================================================================

    MainComponent.h
    Created: 22 Mar 2024 3:41:05pm
    Author:  Austin James

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "../PluginProcessor.h"
#include "../SharedImages.h"
#include "SliderWidgets.h"
#include "ButtonWidgets.h"
#include "MeterWidget.h"

//==============================================================================
/*
*/
class MainComponent  : public juce::Component
{
public:
    MainComponent(ReverbPluginAudioProcessor&);
    ~MainComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    ReverbPluginAudioProcessor&   audioProcessor;
    SharedImages*               m_pSharedImages;
    BigKnob                     bigKnob;
    MediumKnob                  mediumKnob;
    VertSlider                  vertSlider;
    HitPads                     hitPads;
    WheelSlider                 wheelSlider;
    VUMeter                     vuMeter;
    SimpleMeter                 simpleMeter;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
