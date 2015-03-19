#include <stdio.h>
#include <gamepad/gamepad.h>

void Gamepad::init(){
    //TODO check if device is attached
}

void Gamepad::processEvents(){
    //TODO check if device is attached/was removed
    Gamepad_processEvents();

}

void Gamepad::addButton(std::string name, std::uint8_t binding){
    buttons[name] = std::pair<std::uint8_t,bool>(binding,false);
}

void Gamepad::addAxis(std::string name,std::uint8_t xBinding, std::uint8_t yBinding){
    axes[name] = axis(0,0,xBinding,yBinding);
}

Gamepad_device* Gamepad::getNativeDevice(){
    return nativeDevice;
}
