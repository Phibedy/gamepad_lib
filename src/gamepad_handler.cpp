#include <gamepad/gamepad_handler.h>
#include <gamepad_native.h>

//#############################Private methods########################
bool GamepadHandler::verbose = true;

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
}

void GamepadHandler::onDeviceRemoved(struct Gamepad_device * device, void * context) {
    if (verbose) {
        printf("Device ID %u removed with context %p\n", device->deviceID, context);
    }
}

//#############################Public methods#########################
void GamepadHandler::init(){
    Gamepad_deviceAttachFunc(onDeviceAttached, (void *) 0x1);
    Gamepad_deviceRemoveFunc(onDeviceRemoved, (void *) 0x2);
    Gamepad_buttonDownFunc(onButtonDown, (void *) 0x3);
    Gamepad_buttonUpFunc(onButtonUp, (void *) 0x4);
    Gamepad_axisMoveFunc(onAxisMoved, (void *) 0x5);
    Gamepad_init();
}

Gamepad* GamepadHandler::getGamePad(std::string name){
    //TODO
    return nullptr;
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
