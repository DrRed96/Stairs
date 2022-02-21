#include "SfmlUtils.h"

#include "Logger.h"

std::string getEventName(sf::Event::EventType p_type)
{
    std::string events[sf::Event::Count+1] = { "Closed", "Resized", "LostFocus", "GainedFocus", "TextEnetered", "KeyPressed", "KeyReleased", "MouseWheelMoved", "MouseWheelScrolled", "MouseButtonPressed", "MouseButtonReleased", "MouseMoved", "MouseEntered", "MouseLeft", "JoystickButtonPressed", "JoystickButtonReleased", "JoystickMoved", "JoystickConnected", "JoystickDisconnected", "TouchBegan", "TouchMoved", "TouchEnded", "SensorChanged", "Count" };
    return events[p_type];
}
