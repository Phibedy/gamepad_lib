include_directories("include")
#add lib written by someone else
include_directories("lib/include")
add_subdirectory(lib)

#add super stuff
set(SRC
    "src/gamepad.cpp"
)
set(HEADERS
    "include/gamepad/gamepad.h"
)
#========================add controllers=================================
#add XBox controller
set(SRC
    ${SRC}
    "controller/xbox/xbox_controller.cpp"
)
set(HEADERS
    "include/controller/xbox/xbox_controller.h"
    ${HEADERS}
)
#=========================================================
add_library(gamepad_lib SHARED ${SRC} ${HEADERS})
#TODO plattform check
target_link_libraries(gamepad_lib PRIVATE gamepad_external_lib)


