TEMPLATE = app
CONFIG += console c++1z
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += thread

SOURCES += \
        main.cpp \
    DataStructures/ForwardList.cpp \
    DataStructures/Graph.cpp \
    DataStructures/Matrix3d.cpp \
    DataStructures/Vector3d.cpp \
    Algorithms/Geometry/BezierCurve.cpp \
    Algorithms/Strings/ReverseString.cpp \
    Algorithms/Strings/Search.cpp \
    Algorithms/Strings/SplitString.cpp

HEADERS += \
    Algorithms/Geometry/BezierCurve.h \
    Algorithms/Search/BinarySearch.h \
    Algorithms/Sorting/BubbleSort.h \
    Algorithms/Sorting/HeapSort.h \
    Algorithms/Sorting/InsertionSort.h \
    Algorithms/Sorting/MergeSort.h \
    Algorithms/Sorting/QuickSort.h \
    Algorithms/Sorting/SelectionSort.h \
    Algorithms/Strings/ReverseString.h \
    Algorithms/Strings/Search.h \
    Algorithms/Strings/SplitString.h \
    DataStructures/ForwardList.h \
    DataStructures/Graph.h \
    DataStructures/Matrix3d.h \
    DataStructures/PriorityQueue.h \
    DataStructures/Vector3d.h \
    Algorithms/Geometry/BezierCurve.h \
    Algorithms/Search/BinarySearch.h \
    Algorithms/Sorting/BubbleSort.h \
    Algorithms/Sorting/HeapSort.h \
    Algorithms/Sorting/InsertionSort.h \
    Algorithms/Sorting/MergeSort.h \
    Algorithms/Sorting/QuickSort.h \
    Algorithms/Sorting/SelectionSort.h \
    Algorithms/Strings/ReverseString.h \
    Algorithms/Strings/Search.h \
    Algorithms/Strings/SplitString.h \
    DataStructures/ForwardList.h \
    DataStructures/Graph.h \
    DataStructures/Matrix3d.h \
    DataStructures/PriorityQueue.h \
    DataStructures/Vector3d.h \
    Tests/Tests.h
