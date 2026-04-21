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
MainComponent::MainComponent(ReverbPluginAudioProcessor& p) : audioProcessor(p), m_pSharedImages(p.getSharedImages()), bigKnob(m_pSharedImages),
    mediumKnob(m_pSharedImages), vertSlider(m_pSharedImages), hitPads(m_pSharedImages), wheelSlider(m_pSharedImages), vuMeter(audioProcessor), simpleMeter(audioProcessor)
{
    //addAndMakeVisible(bigKnob);
    addAndMakeVisible(mediumKnob);
    addAndMakeVisible(vertSlider);
    addAndMakeVisible(hitPads);
    addAndMakeVisible(wheelSlider);
    addAndMakeVisible(vuMeter);
    addAndMakeVisible(simpleMeter);
    
    wheelSlider.onDragEnd = [this] ()
    {
        wheelSlider.setValue(5.0);
    };
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
    
    //bigKnob.setBounds(700, 250, 215, 245);
    mediumKnob.setBounds(700, 250, 212, 252);
    vertSlider.setBounds(0, 202, 154, 394);
    vuMeter.setBounds(0, 0, 536/2, 280/2);
    simpleMeter.setBounds(250, 250, 50, 250);

    hitPads.setBounds(736, 28, 182, 210);
    wheelSlider.setBounds(500, 200, 160, 406);
    

}
