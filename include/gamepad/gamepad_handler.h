#ifndef GAMEPAD_LIB_GAMEPAD_HANDLER
#define GAMEPAD_LIB_GAMEPAD_HANDLER
#include <gamepad/gamepad.h>
class GamepadHandler{

    static bool verbose;

    static void onButtonDown(struct Gamepad_device * device, unsigned int buttonID, double timestamp, void * context);

    static void onButtonUp(struct Gamepad_device * device, unsigned int buttonID, double timestamp, void * context);

    static void onAxisMoved(struct Gamepad_device * device, unsigned int axisID, float value, float lastValue, double timestamp, void * context);

    static void onDeviceAttached(struct Gamepad_device * device, void * context);

    static void onDeviceRemoved(struct Gamepad_device * device, void * context);
public:
    static void init();
    static Gamepad* getGamePad(std::string name);
    static Gamepad* getGamePad(int iD);
    static void removeGamepad(Gamepad* gamepad);
    /**
     * Could return true or false if a new Device was found
     * @brief detectDevices
     */
    static void detectDevices();

};

#endif //GAMEPAD_LIB_GAMEPAD_HANDLER
