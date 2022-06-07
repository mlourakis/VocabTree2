INCLUDE_DIRECTORIES(.)
INCLUDE_DIRECTORIES(../lib/ann_1.1/include/ANN ../lib/ann_1.1_char/include/ANN ../lib/imagelib ../VocabLib)

LINK_DIRECTORIES(../lib/ann_1.1/src ../lib/ann_1.1_char/src ../lib/imagelib)

ADD_EXECUTABLE(VocabBuildDB VocabBuildDB.cpp)
TARGET_LINK_LIBRARIES(VocabBuildDB PUBLIC OpenMP::OpenMP_CXX Threads::Threads vocab ANN ANN_char image ZLIB::ZLIB)
