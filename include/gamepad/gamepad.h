#ifndef GAMEPAD_LIB_GAMEPAD_H
#define GAMEPAD_LIB_GAMEPAD_H
#include <map>
#include <string>
#include <utility>
#include <cstdint>
#include <gamepad_native.h>
class Gamepad{
    class GamepadHandler;
    friend class GamepadHandler;
public:
    struct axis{
        axis(){
        }
        axis(float x, float y, std::uint8_t xBinding,std::uint8_t yBinding):
            x(x),y(y),xBinding(xBinding),yBinding(yBinding){
        }

        float x;
        float y;
    private:
        std::uint8_t xBinding;
        std::uint8_t yBinding;
    };

    void init();
    void processEvents();
    bool buttonPressed(std::string name);
    axis getAxis(std::string name);
protected:
    void addButton(std::string name, std::uint8_t binding);
    void addAxis(std::string name,std::uint8_t xBinding, std::uint8_t yBinding);
private:
    /**
     * @brief nativeDevice not really native but ok :)
     */
    Gamepad_device* nativeDevice;
    /**
     * string: name
     * uint8_t button used in gamepad lib
     * @brief buttons
     */
    std::map<std::string,std::pair<std::uint8_t,bool>> buttons;
    /**
     * string: name
     * uint8_t axis used in gamepad lib
     * @brief axes
     */
    std::map<std::string,axis> axes;
    Gamepad_device* getNativeDevice();
};


#endif // GAMEPAD_LIB_GAMEPAD_H
