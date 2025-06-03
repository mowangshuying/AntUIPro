set(FRAMELESSHELPER_BUILD_STATIC ON)
set(FRAMELESSHELPER_BUILD_QUICK OFF)
set(FRAMELESSHELPER_NO_INSTALL ON)
add_subdirectory("framelesshelper")

set(TGT framelesshelper)
message("ModName:" "framelesshelper")

add_library(framelesshelper INTERFACE)
target_link_libraries(${TGT}
    INTERFACE
    FramelessHelperCore
    FramelessHelperWidgets
)

