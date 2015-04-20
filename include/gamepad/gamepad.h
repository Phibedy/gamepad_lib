#ifndef GAMEPAD_LIB_GAMEPAD_H
#define GAMEPAD_LIB_GAMEPAD_H
#include <map>
#include <string>
#include <utility>
#include <cstdint>
#include <cmath>

#ifdef USE_CEREAL
#include "lms/serializable.h"
#include "cereal/cerealizable.h"
#include "cereal/cereal.hpp"
#include "cereal/types/map.hpp"
#include "cereal/types/string.hpp"
#include "cereal/types/tuple.hpp"

namespace cereal {

template<class Archive>
void serialize(Archive & archive, std::pair<std::uint8_t,bool> &p) {
    archive(p.first, p.second);
}

}  // namespace cereal
#endif

/**
 *so we don't have to include the library
 */
struct Gamepad_device;
/**
 * @brief The Gamepad class basic class for gamepads
 */
class Gamepad
#ifdef USE_CEREAL
: public lms::Serializable
#endif
{
public:

    /**
     * @brief The GamepadType enum not used yet and not sure if we really need it!
     */
    enum class GamepadType{
        DEFAULT,XBOX
    };

    /**
     * @brief The axis struct used to represent the axes of the controller, if the joystick only has one axis y will be zero
     */
    struct axis{
        friend class Gamepad;
        axis(){
        }
        axis(float x, float y, std::uint8_t xBinding,std::uint8_t yBinding):
            x(x),y(y),xBinding(xBinding),yBinding(yBinding){
        }
        /** value between -1 and 1 */
        float x;
        /** value between -1 and 1 */
        float y;
        /**
         * @brief getAngle
         * @return the angle of the axis in radians "+x"-axis = 0
         */
        float getAngle(){
            return atan2(y,x);
        }

        #ifdef USE_CEREAL
        template<class Archive>
        void serialize(Archive & archive) {
            archive(x, y);
        }
        #endif
    private:
        /**binding for the underlying library */
        std::uint8_t xBinding;
        /**binding for the underlying library */
        std::uint8_t yBinding;
    };

    /**
     * @brief buttonPressed
     * @param name
     * @return true if the button with the given name is pressed
     */
    bool buttonPressed(std::string name);
    /**
     * @brief setButtonState normally called by the framework itself
     * @param name
     * @param pressed
     */
    void setButtonState(std::string name, bool pressed);
    /**
     * @brief setButtonState normally called by the framework itself
     * @param binding
     * @param pressed
     */
    void setButtonState(std::uint8_t binding, bool pressed);
    /**
     * @brief setAxisState normally called by the framework itself
     * @param binding
     * @param state
     */
    void setAxisState(std::uint8_t binding, float state);
    /**
     * @brief getAxis
     * @param name
     * @return the axis by the given name
     */
    axis getAxis(std::string name);

    const Gamepad_device* getNativeDevice();
    void setNativeDevice(Gamepad_device* device);

    /**
     * @brief clear clears buttons and axes
     */
    void clear();
    /**
     * @brief clearButtons removes binding of buttons
     */
    void clearButtons();
    /**
     * @brief clearAxes removes binding of axes
     */
    void clearAxes();

    void printButtons();
    void printAxes();
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
//stuff for serialize

#ifdef USE_CEREAL
public:
    CEREAL_SERIALIZATION()

    template<class Archive>
    void serialize(Archive & archive) {
        archive(axes, buttons);
    }
#endif
};


#endif // GAMEPAD_LIB_GAMEPAD_H
