#include_directories("include")
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
    "include/gamepad_native.h"
    "include/gamepad_native_private.h"
)

add_library(gamepad_external_lib SHARED ${SRC} ${HEADERS})
if(UNIX)
    target_link_libraries(gamepad_external_lib PRIVATE pthread)
endif(UNIX)
#TODO windows macosx support

