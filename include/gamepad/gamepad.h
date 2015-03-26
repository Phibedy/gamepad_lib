#ifndef GAMEPAD_LIB_GAMEPAD_H
#define GAMEPAD_LIB_GAMEPAD_H
#include <map>
#include <string>
#include <utility>
#include <cstdint>
#include <cmath>
#include <lms/serializable.h>
/**
 *so we don't have to include the library
 */
struct Gamepad_device;
/**
 * @brief The Gamepad class basic class for gamepads
 */
class Gamepad
#ifdef USE_CEREAL
:lms::Serializable
#endif
{
public:
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

    void printButtons();
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
//stuff for serialize

#ifdef USE_CEREAL
public:
    /**
     * @brief Serialize the object into the given output stream.
     * @param os output stream to write in
     */
    virtual void serialize(std::ostream &os) const;

    /**
     * @brief Deserialize the object from the given input stream.
     * @param is input stream to read from
     */
    virtual void deserialize(std::istream &is);
#endif
};


#endif // GAMEPAD_LIB_GAMEPAD_H
