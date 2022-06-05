INCLUDE_DIRECTORIES(.)
INCLUDE_DIRECTORIES(../lib/ann_1.1/include/ANN ../lib/ann_1.1_char/include/ANN ../lib/imagelib)


SET(VOCABLIB_SRCS keys2.cpp kmeans.cpp kmeans_kd.cpp VocabFlatNode.cpp VocabTreeBuild.cpp VocabTree.cpp VocabTreeIO.cpp VocabTreeUtil.cpp)
SET(VOCABLIB_HDRS keys2.h kmeans.h kmeans_kd.h VocabTree.h)

IF(OPENMP_FOUND)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
ENDIF()

ADD_LIBRARY(vocab ${VOCABLIB_SRCS} ${VOCABLIB_HDRS})
