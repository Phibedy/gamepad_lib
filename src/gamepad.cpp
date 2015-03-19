
#include <gamepad.h>
#include <stdio.h>
#include <gamepad/gamepad.h>
static bool verbose = true;

void onButtonDown(struct Gamepad_device * device, unsigned int buttonID, double timestamp, void * context) {
    if (verbose) {
        printf("Button %u down on device %u at %f with context %p\n", buttonID, device->deviceID, timestamp, context);
    }
}

void onButtonUp(struct Gamepad_device * device, unsigned int buttonID, double timestamp, void * context) {
    if (verbose) {
        printf("Button %u up on device %u at %f with context %p\n", buttonID, device->deviceID, timestamp, context);
    }
}

void onAxisMoved(struct Gamepad_device * device, unsigned int axisID, float value, float lastValue, double timestamp, void * context) {
    if (verbose) {
        printf("Axis %u moved from %f to %f on device %u at %f with context %p\n", axisID, lastValue, value, device->deviceID, timestamp, context);
    }
}

void onDeviceAttached(struct Gamepad_device * device, void * context) {
    if (verbose) {
        printf("Device ID %u attached (vendor = 0x%X; product = 0x%X) with context %p\n", device->deviceID, device->vendorID, device->productID, context);
    }
}

void onDeviceRemoved(struct Gamepad_device * device, void * context) {
    if (verbose) {
        printf("Device ID %u removed with context %p\n", device->deviceID, context);
    }
}

void Gamepad::init(){
    //TODO check if device is attached
    Gamepad_deviceAttachFunc(onDeviceAttached, (void *) 0x1);
    Gamepad_deviceRemoveFunc(onDeviceRemoved, (void *) 0x2);
    Gamepad_buttonDownFunc(onButtonDown, (void *) 0x3);
    Gamepad_buttonUpFunc(onButtonUp, (void *) 0x4);
    Gamepad_axisMoveFunc(onAxisMoved, (void *) 0x5);
    Gamepad_init();
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
