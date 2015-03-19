#include <stdio.h>
#include <gamepad_native.h>
#include <gamepad/gamepad.h>


void Gamepad::addButton(std::string name, std::uint8_t binding){
    buttons[name] = std::pair<std::uint8_t,bool>(binding,false);
}

void Gamepad::addAxis(std::string name,std::uint8_t xBinding, std::uint8_t yBinding){
    axes[name] = axis(0,0,xBinding,yBinding);
}

const Gamepad_device* Gamepad::getNativeDevice(){
    return nativeDevice;
}


void Gamepad::setNativeDevice(Gamepad_device* device){
    nativeDevice = device;
}
