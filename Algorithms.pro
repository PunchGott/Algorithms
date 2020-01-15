TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Algorithms/BubbleSort.cpp \
        Algorithms/InsertionSort.cpp \
        Algorithms/MergeSort.cpp \
        Algorithms/QuickSort.cpp \
        Algorithms/SelectSort.cpp \
        Algorithms/TreeSort.cpp \
        main.cpp

HEADERS += \
    StructureData/LinkedList/LinkedList.h
