INCLUDE_DIRECTORIES(.)
INCLUDE_DIRECTORIES(../lib/ann_1.1/include/ANN ../lib/ann_1.1_char/include/ANN ../lib/imagelib ../VocabLib)

LINK_DIRECTORIES(../lib/ann_1.1/src ../lib/ann_1.1_char/src ../lib/imagelib)

ADD_EXECUTABLE(VocabMatch VocabMatch.cpp)
TARGET_LINK_LIBRARIES(VocabMatch PUBLIC OpenMP::OpenMP_CXX Threads::Threads vocab ANN ANN_char image ZLIB::ZLIB)

ADD_EXECUTABLE(VocabMatch_desc VocabMatch_desc.cpp)
TARGET_LINK_LIBRARIES(VocabMatch_desc PUBLIC OpenMP::OpenMP_CXX Threads::Threads vocab ANN ANN_char image ZLIB::ZLIB)


ADD_EXECUTABLE(VocabMatchScript VocabMatchScript.cpp)
TARGET_LINK_LIBRARIES(VocabMatchScript PUBLIC OpenMP::OpenMP_CXX Threads::Threads vocab ANN ANN_char image ZLIB::ZLIB)

ADD_EXECUTABLE(VocabMatchScript_desc VocabMatchScript_desc.cpp)
TARGET_LINK_LIBRARIES(VocabMatchScript_desc PUBLIC OpenMP::OpenMP_CXX Threads::Threads vocab ANN ANN_char image ZLIB::ZLIB)
