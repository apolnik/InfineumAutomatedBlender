cmake_minimum_required(VERSION 2.8.9)
project(Cmake)
 
#Bring the headers, such as Student.h into the project
include_directories(Tools/Include)
include_directories(Tools)
include_directories(Actuator/Stepper)
include_directories(Actuator/Stepper/Proximity)
include_directories(Actuator/DC_Motor)
include_directories(Actuator/DC_Motor/RotEncoder)
include_directories(Actuator)
include_directories(FluidTranCntrl)
include_directories(HeatCntrl)
include_directories(HeatCntrl/tempMeasurement)
include_directories(mixCntrl)
include_directories(PumpCntrl)
include_directories(SystemInterface)
include_directories(SystemInterface/Logger)
include_directories(SystemInterface/AlarmSys)
include_directories(ValveCntrl)
include_directories(weightMeasurement)
include_directories(topLevel)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

#Can manually add the sources using the set command as follows:
#set(SOURCES src/mainapp.cpp src/Student.cpp)
#include_directories(${Qt5Widgets_INCLUDE_DIRS})

#However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES "./*.cpp" "./*.c" "./*/*.cpp" "./*/*.c" "./*/*/*.cpp" "./*/*/*.c" "./*/*/*/*.cpp" "./*/*/*/*.c" "./*/*/*/*/*.cpp" "./*/*/*/*/*.c")
SET(GCC_COVERAGE_COMPILE_FLAGS "-pthread -lrt")
add_definitions(${GCC_COVERAGE_COMPILE_FLAGS})
find_package (Threads)
set(CMAKE_EXE_LINKER_FLAGS "-lrt")
#find_package(Qt5Widgets)
#find_package(Qt5Core)
#find_package(Qt5Gui)
#QT5_WRAP_CPP(Cmake_hdr_moc systeminterfaceqt.h)
#QT5_WRAP_UI(Cmake_form_hdr systeminterfaceqt.ui)
#include_directories(${Qt5Widgets_INCLUDES})
find_package(Qt4 4.4.3 REQUIRED QtGui QtXml)
#add_definitions(${Qt5Widgets_DEFINITIONS})

set(CMAKE_CXX_FLAGS "${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")

add_executable(testStudent ${SOURCES})

target_link_libraries (testStudent ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(testStudent rt)
#target_link_libraries(testStudent Qt5::Widgets)
#target_link_libraries(testStudent ${Qt5Widgets_LIBRARIES})

#qt5_use_modules(testStudent Core Gui Widgets)
target_link_libraries(testStudent Qt4::QtGui Qt4::QtXml)


