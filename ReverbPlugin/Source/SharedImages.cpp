/*
  ==============================================================================

    SharedImages.cpp
    Created: 24 Mar 2024 11:10:15am
    Author:  Austin James

  ==============================================================================
*/

#include "SharedImages.h"

void SharedImages::loadImages()
{
    
    
    m_BackgroundImage = juce::ImageCache::getFromMemory(BinaryData::bg_2_png, BinaryData::bg_2_pngSize);
    
    m_BigKnob = juce::ImageCache::getFromMemory(BinaryData::Knob_big_png, BinaryData::Knob_big_pngSize);
    
    m_MediumKnob = juce::ImageCache::getFromMemory(BinaryData::Knob_middle_png, BinaryData::Knob_middle_pngSize);
    
    m_VertSlider = juce::ImageCache::getFromMemory(BinaryData::Slider_vertical_png, BinaryData::Slider_vertical_pngSize);
    
    m_HorzSlider = juce::ImageCache::getFromMemory(BinaryData::Slider_horizontal_png, BinaryData::Slider_horizontal_pngSize);
    
    m_PadButtonOn = juce::ImageCache::getFromMemory(BinaryData::Button_en_1_png, BinaryData::Button_en_1_pngSize);
    
    m_PadButtonOff = juce::ImageCache::getFromMemory(BinaryData::Button_dis_1_png, BinaryData::Button_dis_1_pngSize);
    
    m_SwitchUp = juce::ImageCache::getFromMemory(BinaryData::Switch_en_png, BinaryData::Switch_en_pngSize);
    
    m_SwitchDown = juce::ImageCache::getFromMemory(BinaryData::Switch_dis_png, BinaryData::Switch_dis_pngSize);
    
    m_VUMeter = juce::ImageCache::getFromMemory(BinaryData::vu_meter_png, BinaryData::vu_meter_pngSize);
    
    m_Wheel = juce::ImageCache::getFromMemory(BinaryData::Wheel_png, BinaryData::Wheel_pngSize);

}
