cmake_minimum_required(VERSION 3.5)

set(HEADERS helix.h ellipse.h circle.h curve.h)
set(SOURCES helix.cpp ellipse.cpp circle.cpp curve.cpp)

add_library(curves SHARED ${HEADERS} ${SOURCES})
