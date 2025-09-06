set(app_options)

if(CMAKE_BUILD_TYPE STREQUAL "Release")
if(APPLE)
    list(APPEND app_options MACOSX_BUNDLE)
elseif(WIN32)
    list(APPEND app_options WIN32)
endif()
endif()

list(APPEND app_options main.cpp ui/helplogic.cpp ui/mapslogic.cpp ui/screenmanager.cpp resources.qrc)

qt_add_executable(${PROJECT_NAME} ${app_options})

target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Quick)

install(TARGETS ${PROJECT_NAME}
    BUNDLE DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
