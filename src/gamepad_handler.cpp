#include <gamepad/gamepad_handler.h>
#include <gamepad_native.h>
#include <iostream>
//#############################Private methods########################
bool GamepadHandler::verbose = true;
std::vector<Gamepad_device*> GamepadHandler::connectedDevices;
std::vector<Gamepad*> GamepadHandler::runningGamepads;

void GamepadHandler::onButtonDown(struct Gamepad_device * device, unsigned int buttonID, double timestamp, void * context) {
    if (verbose) {
        printf("Button %u down on device %u at %f with context %p\n", buttonID, device->deviceID, timestamp, context);
    }
}

void GamepadHandler::onButtonUp(struct Gamepad_device * device, unsigned int buttonID, double timestamp, void * context) {
    if (verbose) {
        printf("Button %u up on device %u at %f with context %p\n", buttonID, device->deviceID, timestamp, context);
    }
}

void GamepadHandler::onAxisMoved(struct Gamepad_device * device, unsigned int axisID, float value, float lastValue, double timestamp, void * context) {
    if (verbose) {
        printf("Axis %u moved from %f to %f on device %u at %f with context %p\n", axisID, lastValue, value, device->deviceID, timestamp, context);
    }
}

void GamepadHandler::onDeviceAttached(struct Gamepad_device * device, void * context) {
    if (verbose) {
        printf("Device ID %u attached (vendor = 0x%X; product = 0x%X; device = %s) with context %p\n", device->deviceID, device->vendorID, device->productID,device->description, context);
    }
    //Check if device was already connected
    for(Gamepad_device *cd :connectedDevices){
        if(cd==device)
            return;
    }
    connectedDevices.push_back(device);

}

void GamepadHandler::onDeviceRemoved(struct Gamepad_device * device, void * context) {
    if (verbose) {
        printf("Device ID %u removed with context %p\n", device->deviceID, context);
    }
}

//#############################Public methods#########################
void GamepadHandler::init(){
    static bool first =true;
    if(first){
        first = false;
        Gamepad_deviceAttachFunc(onDeviceAttached, (void *) 0x1);
        Gamepad_deviceRemoveFunc(onDeviceRemoved, (void *) 0x2);
        Gamepad_buttonDownFunc(onButtonDown, (void *) 0x3);
        Gamepad_buttonUpFunc(onButtonUp, (void *) 0x4);
        Gamepad_axisMoveFunc(onAxisMoved, (void *) 0x5);
        Gamepad_init();
    }else{
        std::cerr << "TRIED TO CALL GamepadHandler::init() twice"<<std::endl;
    }
}


Gamepad_device * GamepadHandler::getDevicePerName(std::string name, bool fullname){
    Gamepad_device *found = nullptr;
    for(Gamepad_device *d : connectedDevices){
        if(fullname){
            if(strcmp(d->description,name.c_str()) == 0){
                found = d;
            }
        }else{
            if(strstr(d->description, name.c_str()) != nullptr){
                found = d;
            }
        }
    }
    return found;
}

Gamepad* GamepadHandler::getGamePad(int iD){
    //TODO
    return nullptr;
}

void GamepadHandler::removeGamepad(Gamepad* gamepad){
    //TODO
}

void GamepadHandler::detectDevices(){
    Gamepad_detectDevices();
}

void GamepadHandler::processEvents(){
    Gamepad_processEvents();
}
