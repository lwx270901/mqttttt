cmake_minimum_required(VERSION 3.10)
project(mqtt-publisher)

find_package(PkgConfig REQUIRED)
pkg_check_modules(MOSQUITTO REQUIRED libmosquitto)

include_directories(${MOSQUITTO_INCLUDE_DIRS})
link_directories(${MOSQUITTO_LIBRARY_DIRS})



add_executable(mqtt-subscriber mqtt_subscriber.cpp)
target_link_libraries(mqtt-subscriber ${MOSQUITTO_LIBRARIES})

add_executable(mqtt-publisher mqtt_publisher.cpp)
target_link_libraries(mqtt-publisher ${MOSQUITTO_LIBRARIES})