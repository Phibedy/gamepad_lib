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

const Gamepad_device* Gamepad::getNativeDevice(){
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

void Gamepad::printButtons(){
    std::cout << "###################### BUTTONS ######################"<<std::endl;
    for(auto &button:buttons){
        std::cout << button.first << " " << button.second.second << std::endl;
    }
}

void Gamepad::printAxes(){
    std::cout << "###################### AXIS ######################"<<std::endl;
    for(auto &axis:axes){
        std::cout << axis.first << ": x: " << axis.second.x << " y: "<< axis.second.y << std::endl;
    }
}
