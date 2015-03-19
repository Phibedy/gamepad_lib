include_directories("include")
set(SRC
    "src/Gamepad_private.c"
)
if(UNIX)
    set(SRC
        ${SRC}
        "src/Gamepad_linux.c"
)
endif(UNIX)
#TODO windows macosx support
set(HEADERS
    "include/gamepad/Gamepad.h"
    "include/gamepad/Gamepad_private.h"
)

add_library(gamepad_lib SHARED ${SRC} ${HEADERS})
#TODO plattform check
target_link_libraries(gamepad_lib PRIVATE pthread)


