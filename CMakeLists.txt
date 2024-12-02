cmake_minimum_required(VERSION 3.16)

project(pgpcodingchallenge VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.5 REQUIRED COMPONENTS Quick)

qt_standard_project_setup(REQUIRES 6.5)

qt_add_executable(apppgpcodingchallenge
    main.cpp
)

qt_add_qml_module(apppgpcodingchallenge
    URI pgpcodingchallenge
    VERSION 1.0
    QML_FILES
        Main.qml
        SOURCES
        SOURCES signalemitter.h signalemitter.cpp
        SOURCES configloader.h configloader.cpp
        RESOURCES README.md
        RESOURCES SPECS.md
        QML_FILES backend_1.json
        QML_FILES backend_3.json
        QML_FILES backend_5.json
        QML_FILES frontend.json
        QML_FILES ValueTracker.qml
        RESOURCES
        SOURCES contextpropertylookup.h contextpropertylookup.cpp
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(apppgpcodingchallenge PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.apppgpcodingchallenge
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(apppgpcodingchallenge
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS apppgpcodingchallenge
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
