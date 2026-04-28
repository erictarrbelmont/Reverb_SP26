/*
  ==============================================================================

    MainComponent.cpp
    Created: 22 Mar 2024 3:41:05pm
    Author:  Austin James

  ==============================================================================
*/

#include <JuceHeader.h>
#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent(ReverbPluginAudioProcessor& p) : audioProcessor(p), m_pSharedImages(p.getSharedImages()),
    reverbTime(m_pSharedImages), diffusion(m_pSharedImages), wetDry(m_pSharedImages), LPF(m_pSharedImages)
{
    reverbTime.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    reverbTime.setTextBoxStyle(juce::Slider::TextBoxBelow,true,50,25);
    reverbTimeLabel.setText(audioProcessor.aptvs.getParameter("REVERBTIME")->getName(5),juce::dontSendNotification);
    reverbTimeLabel.setJustificationType(juce::Justification::centredTop);
    reverbTimeLabel.attachToComponent(&reverbTime, false);
    addAndMakeVisible(reverbTime);
    reverbTimeAttatchment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.aptvs,"REVERBTIME",reverbTime);
    
    diffusion.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    diffusion.setTextBoxStyle(juce::Slider::TextBoxBelow,true,50,25);
    diffusionLabel.setText(audioProcessor.aptvs.getParameter("DIFFUSION")->getName(5),juce::dontSendNotification);
    diffusionLabel.setJustificationType(juce::Justification::centredTop);
    diffusionLabel.attachToComponent(&diffusion, false);
    addAndMakeVisible(diffusion);
    diffusionAttatchment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.aptvs,"DIFFUSION",diffusion);
    
    wetDry.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    wetDry.setTextBoxStyle(juce::Slider::TextBoxBelow,true,50,25);
    wetDryLabel.setText(audioProcessor.aptvs.getParameter("WETDRY")->getName(5),juce::dontSendNotification);
    wetDryLabel.setJustificationType(juce::Justification::centredTop);
    wetDryLabel.attachToComponent(&wetDry, false);
    addAndMakeVisible(wetDry);
    wetDryAttatchment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.aptvs,"WETDRY",wetDry);
    
    LPF.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    LPF.setTextBoxStyle(juce::Slider::TextBoxBelow,true,50,25);
    LPFLabel.setText(audioProcessor.aptvs.getParameter("LPF")->getName(5),juce::dontSendNotification);
    LPFLabel.setJustificationType(juce::Justification::centredTop);
    LPFLabel.attachToComponent(&LPF, false);
    addAndMakeVisible(LPF);
    LPFAttatchment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.aptvs,"LPF",LPF);
}

MainComponent::~MainComponent()
{
}

void MainComponent::paint (juce::Graphics& g)
{
    g.drawImage(m_pSharedImages->getBackgroundImage(), 0, 0, getWidth(), getHeight(), 0, 0, 2000, 1400);
    
}

void MainComponent::resized()
{
    reverbTime.setBounds(50,50,100,100);
    diffusion.setBounds(250,50,100,100);
    wetDry.setBounds(50,150,100,100);
    LPF.setBounds(250,150,100,100);

}
