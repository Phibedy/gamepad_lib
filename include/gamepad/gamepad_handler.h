#ifndef GAMEPAD_LIB_GAMEPAD_HANDLER
#define GAMEPAD_LIB_GAMEPAD_HANDLER
#include <gamepad/gamepad.h>
#include <vector>
#include <cstring>
class GamepadHandler{

    static std::vector<Gamepad_device*> connectedDevices;
    static std::vector<Gamepad*> runningGamepads;

    static bool verbose;

    static void onButtonDown(struct Gamepad_device * device, unsigned int buttonID, double timestamp, void * context);

    static void onButtonUp(struct Gamepad_device * device, unsigned int buttonID, double timestamp, void * context);

    static void onAxisMoved(struct Gamepad_device * device, unsigned int axisID, float value, float lastValue, double timestamp, void * context);

    static void onDeviceAttached(struct Gamepad_device * device, void * context);

    static void onDeviceRemoved(struct Gamepad_device * device, void * context);

    static Gamepad_device * getDevicePerName(std::string name, bool fullname);
public:
    /**
     * @brief init should only be called once!
     */
    static void init();
    /**
     * @brief getGamePad
     * @param name
     * @param fullname if false the name can be only a part of the device-name
     * @return
     */
    template<class T>
    static T* getGamePad(std::string name, bool fullname = true){
        //TODO check if device is already in use
        Gamepad_device *found = getDevicePerName(name,fullname);
        //no valid Gamepad found
        if(found == nullptr)
            return nullptr;
        T *gamepad = new T();
        gamepad->setNativeDevice(found);

        return gamepad;
    }
    // TODO write template function
    static Gamepad* getGamePad(int iD);
    static void removeGamepad(Gamepad* gamepad);
    /**
     * Could return true or false if a new Device was found
     * @brief detectDevices
     */
    static void detectDevices();
    /**
     * @brief processEvents call this method to update all gamepads
     */
    static void processEvents();

};

#endif //GAMEPAD_LIB_GAMEPAD_HANDLER
