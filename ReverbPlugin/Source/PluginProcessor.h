/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "SharedImages.h"

//==============================================================================
/**
*/
class ReverbPluginAudioProcessor  : public juce::AudioProcessor
{
public:
    //==============================================================================
    ReverbPluginAudioProcessor();
    ~ReverbPluginAudioProcessor() override;

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    //==============================================================================
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const juce::String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const juce::String getProgramName (int index) override;
    void changeProgramName (int index, const juce::String& newName) override;

    //==============================================================================
    void getStateInformation (juce::MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

    SharedImages* getSharedImages()                         { return m_pSharedImagesPtr;        }

    
    float getOutputLevel (bool isRightChannel)
    {
        if (isRightChannel)
            return outputLevel[1].load();
        else
            return outputLevel[0].load();
    }
    
private:
    
    juce::SharedResourcePointer<SharedImages>                   m_pSharedImagesPtr;

    std::atomic<float>                                          outputLevel[2] = { 0.0f, 0.0f };     // 0 for left channel, 1 for right channel
        
    juce::dsp::BallisticsFilter<float>                          ballisticsFilterOutput;
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ReverbPluginAudioProcessor)
};
