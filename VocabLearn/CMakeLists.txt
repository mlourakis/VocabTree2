INCLUDE_DIRECTORIES(.)
INCLUDE_DIRECTORIES(../lib/ann_1.1/include/ANN ../lib/ann_1.1_char/include/ANN ../lib/imagelib ../VocabLib)

ADD_EXECUTABLE(VocabLearn VocabLearn.cpp)
TARGET_LINK_LIBRARIES(VocabLearn PUBLIC OpenMP::OpenMP_CXX Threads::Threads vocab ANN ANN_char image ZLIB::ZLIB)
LINK_DIRECTORIES(../lib/ann_1.1/src ../lib/ann_1.1_char/src ../lib/imagelib)

