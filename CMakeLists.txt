cmake_minimum_required (VERSION 3.5 FATAL_ERROR)
project (graphy)
project (graphy-demo)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SFML_INCLUDE_DIR ~/include)
set(SFML_LIBRARY_DIR ~/lib)

include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/src/internal/include)
include_directories(${SFML_INCLUDE_DIR})

link_directories(${SFML_LIBRARY_DIR})

add_definitions(-D_GLIBCXX_USE_CXX11_ABI=0)

set(GRAPH_DIR ${PROJECT_SOURCE_DIR}/src/Graph)
set(GRAPHABLES_DIR ${PROJECT_SOURCE_DIR}/src/Graphables)
set(INTERNAL_DIR ${PROJECT_SOURCE_DIR}/src/internal)
set(EXAMPLES_DIR ${PROJECT_SOURCE_DIR}/examples)

set (GRAPHY_SOURCE
    ${GRAPH_DIR}/ctors.cpp
    ${GRAPH_DIR}/graphables.cpp
    ${GRAPH_DIR}/helpers.cpp
    ${GRAPH_DIR}/map.cpp
    ${GRAPH_DIR}/view.cpp
    ${GRAPH_DIR}/window.cpp
    ${GRAPHABLES_DIR}/Axis.cpp
    ${GRAPHABLES_DIR}/ColorMap.cpp
    ${GRAPHABLES_DIR}/DataSet.cpp
    ${GRAPHABLES_DIR}/Equation.cpp
    ${GRAPHABLES_DIR}/Graphable.cpp
    ${GRAPHABLES_DIR}/Histogram.cpp
    ${GRAPHABLES_DIR}/ImplicitEquation.cpp
    ${GRAPHABLES_DIR}/Point.cpp
    ${INTERNAL_DIR}/random_color.cpp
    ${INTERNAL_DIR}/SFDraw.cpp
    ${INTERNAL_DIR}/StatusBar.cpp
)
set (GRAPHY_DEMO_SOURCE
    ${EXAMPLES_DIR}/demo.cpp
    )
    

add_library(graphy SHARED ${GRAPHY_SOURCE})
target_link_libraries(graphy sfml-audio sfml-network sfml-graphics sfml-system sfml-window)

add_executable(graphy-demo ${GRAPHY_DEMO_SOURCE})
target_link_libraries(graphy-demo graphy)
