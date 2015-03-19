#ifndef GAMEPAD_LIB_GAMEPAD_H
#define GAMEPAD_LIB_GAMEPAD_H
#include <map>
#include <string>
#include <utility>
#include <cstdint>
//#include <gamepad_native.h>
struct Gamepad_device;
class Gamepad{
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

    /**
     * @brief buttonPressed
     * @param name
     * @return true if the button with the given name is pressed
     */
    bool buttonPressed(std::string name);
    /**
     * @brief getAxis
     * @param name
     * @return the axis by the given name
     */
    axis getAxis(std::string name);

    const Gamepad_device* getNativeDevice();
    void setNativeDevice(Gamepad_device* device);
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
};


#endif // GAMEPAD_LIB_GAMEPAD_H
