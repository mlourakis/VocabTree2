INCLUDE_DIRECTORIES(.)
INCLUDE_DIRECTORIES(../lib/ann_1.1/include/ANN ../lib/ann_1.1_char/include/ANN ../lib/imagelib ../VocabLib)

LINK_DIRECTORIES(../lib/ann_1.1/src ../lib/ann_1.1_char/src ../lib/imagelib)

ADD_EXECUTABLE(VocabCompare VocabCompare.cpp)
TARGET_LINK_LIBRARIES(VocabCompare PUBLIC OpenMP::OpenMP_CXX Threads::Threads vocab ANN ANN_char image ZLIB::ZLIB)

ADD_EXECUTABLE(VocabCombine VocabCombine.cpp)
TARGET_LINK_LIBRARIES(VocabCombine PUBLIC OpenMP::OpenMP_CXX Threads::Threads vocab ANN ANN_char image ZLIB::ZLIB)
