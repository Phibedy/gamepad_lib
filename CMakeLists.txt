include_directories("include")
#add lib written by someone else
include_directories("lib/include")
add_subdirectory(lib)

#add super stuff
set(SRC
    "src/gamepad.cpp"
    "src/gamepad_handler.cpp"
)
set(HEADERS
    "include/gamepad/gamepad.h"
    "include/gamepad/gamepad_handler.h"
    "include/gamepad/gamepad_types.h"
)
#=========================================================
add_library(gamepad_lib SHARED ${SRC} ${HEADERS})
target_link_libraries(gamepad_lib PRIVATE gamepad_external_lib)


