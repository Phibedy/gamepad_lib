#include <stdio.h>
#include <gamepad_native.h>
#include <gamepad/gamepad.h>
#include <cstdint>
#include <iostream>

void Gamepad::addButton(std::string name, std::uint8_t binding){
    buttons[name] = std::pair<std::uint8_t,bool>(binding,false);
    std::cout<< "added button: " << name << buttons[name].second << std::endl;
}

void Gamepad::addAxis(std::string name,std::uint8_t xBinding, std::uint8_t yBinding){
    axes[name] = axis(0,0,xBinding,yBinding);
}

const Gamepad_device* Gamepad::getNativeDevice() const{
    return nativeDevice;
}


void Gamepad::setNativeDevice(Gamepad_device* device){
    nativeDevice = device;
}


void Gamepad::setButtonState(std::string name, bool pressed){
    std::pair<std::uint8_t,bool>&button = buttons[name];
    button.second = pressed;
}

void Gamepad::setButtonState(std::uint8_t binding, bool pressed){
    for(auto &button : buttons){
        if(button.second.first == binding){
            button.second.second = pressed;
            return;
        }
    }
}

void Gamepad::setAxisState(std::uint8_t binding, float state){
    for(auto &ax : axes){
        if(ax.second.xBinding == binding){
            ax.second.x = state;
            return;
        }
        else if(ax.second.yBinding == binding){
            ax.second.y = state;
            return;
        }
    }
}


void Gamepad::connected(bool isConnected) {
    this->isConnected = isConnected;
}

bool Gamepad::connected() const {
    return isConnected;
}

void Gamepad::updateTimestamp() {
    this->lastUpdate = lms::extra::PrecisionTime::now();
}

lms::extra::PrecisionTime Gamepad::timestamp() const {
    return lastUpdate;
}

void Gamepad::clear(){
    clearButtons();
    clearAxes();
}

void Gamepad::clearButtons(){
    buttons.clear();
}

void Gamepad::clearAxes(){
    axes.clear();
}


const Gamepad::axis& Gamepad::getAxis(std::string name) const{
    auto res= axes.find(name);
    if(res == axes.end()){
        //nice error I dont't care about
    }
    return res->second;
}


bool Gamepad::buttonPressed(std::string name) const{
    auto res= buttons.find(name);
    if(res == buttons.end()){
        //nice error I dont't care about
        return false;
    }
    return res->second.second;
}

void Gamepad::printButtons() const{
    std::cout << "###################### BUTTONS ######################"<<std::endl;
    for(auto &button:buttons){
        std::cout << button.first << " " << button.second.second << std::endl;
    }
}

void Gamepad::printAxes() const{
    std::cout << "###################### AXIS ######################"<<std::endl;
    for(auto &axis:axes){
        std::cout << axis.first << ": x: " << axis.second.x << " y: "<< axis.second.y << std::endl;
    }
}
