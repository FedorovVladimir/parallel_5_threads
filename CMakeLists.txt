cmake_minimum_required(VERSION 3.16)
project(parallel_5_threads)

set(CMAKE_CXX_STANDARD 14)

add_executable(parallel_5_threads main.cpp lib/BinarySemaphore.cpp lib/BinarySemaphore.h lib/IntegerChannel.cpp lib/IntegerChannel.h processes/farm.h processes/market.h processes/warehouse.h processes/bakery.h processes/meat_processing_plant.h processes/burger_joint.h)