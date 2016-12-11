#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Buffer.o \
	${OBJECTDIR}/BufferNode.o \
<<<<<<< HEAD
	${OBJECTDIR}/Component.o \
	${OBJECTDIR}/ComponentCursor.o \
=======
>>>>>>> 779dac4661bc2ddf5ac78fd0dcc9a2646c710e32
	${OBJECTDIR}/HashTable.o \
	${OBJECTDIR}/Index.o \
	${OBJECTDIR}/IndexNode.o \
	${OBJECTDIR}/bfs.o \
	${OBJECTDIR}/bucket.o \
<<<<<<< HEAD
=======
	${OBJECTDIR}/cc.o \
>>>>>>> 779dac4661bc2ddf5ac78fd0dcc9a2646c710e32
	${OBJECTDIR}/graphLibrary.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/queue.o \
	${OBJECTDIR}/scc.o \
	${OBJECTDIR}/stack.o \
	${OBJECTDIR}/updateIndex.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f2 \
	${TESTDIR}/TestFiles/f1

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/shortestpathproblem

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/shortestpathproblem: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/shortestpathproblem ${OBJECTFILES} ${LDLIBSOPTIONS}

<<<<<<< HEAD
${OBJECTDIR}/Buffer.o: Buffer.cpp 
=======
${OBJECTDIR}/Buffer.o: Buffer.cpp
>>>>>>> 779dac4661bc2ddf5ac78fd0dcc9a2646c710e32
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Buffer.o Buffer.cpp

<<<<<<< HEAD
${OBJECTDIR}/BufferNode.o: BufferNode.cpp 
=======
${OBJECTDIR}/BufferNode.o: BufferNode.cpp
>>>>>>> 779dac4661bc2ddf5ac78fd0dcc9a2646c710e32
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/BufferNode.o BufferNode.cpp

<<<<<<< HEAD
${OBJECTDIR}/Component.o: Component.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Component.o Component.cpp

${OBJECTDIR}/ComponentCursor.o: ComponentCursor.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ComponentCursor.o ComponentCursor.cpp

${OBJECTDIR}/HashTable.o: HashTable.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/HashTable.o HashTable.cpp

${OBJECTDIR}/Index.o: Index.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Index.o Index.cpp

${OBJECTDIR}/IndexNode.o: IndexNode.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/IndexNode.o IndexNode.cpp

${OBJECTDIR}/bfs.o: bfs.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/bfs.o bfs.cpp
=======
${OBJECTDIR}/HashTable.o: HashTable.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/HashTable.o HashTable.cpp

${OBJECTDIR}/Index.o: Index.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Index.o Index.cpp

${OBJECTDIR}/IndexNode.o: IndexNode.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/IndexNode.o IndexNode.cpp

${OBJECTDIR}/bfs.o: bfs.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/bfs.o bfs.cpp

${OBJECTDIR}/bucket.o: bucket.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/bucket.o bucket.cpp

${OBJECTDIR}/cc.o: cc.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/cc.o cc.cpp

${OBJECTDIR}/graphLibrary.o: graphLibrary.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/graphLibrary.o graphLibrary.cpp

${OBJECTDIR}/main.o: main.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp
>>>>>>> 779dac4661bc2ddf5ac78fd0dcc9a2646c710e32

${OBJECTDIR}/bucket.o: bucket.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/bucket.o bucket.cpp

${OBJECTDIR}/graphLibrary.o: graphLibrary.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/graphLibrary.o graphLibrary.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/queue.o: queue.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/queue.o queue.cpp

${OBJECTDIR}/scc.o: scc.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/scc.o scc.cpp

${OBJECTDIR}/stack.o: stack.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/stack.o stack.cpp

${OBJECTDIR}/updateIndex.o: updateIndex.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/updateIndex.o updateIndex.cpp

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-conf ${TESTFILES}
${TESTDIR}/TestFiles/f2: ${TESTDIR}/tests/newsimpletest1.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f2 $^ ${LDLIBSOPTIONS} 

${TESTDIR}/TestFiles/f1: ${TESTDIR}/tests/tinyGraphBFSTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS} 


${TESTDIR}/tests/newsimpletest1.o: tests/newsimpletest1.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -I. -std=c++11 -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/newsimpletest1.o tests/newsimpletest1.cpp


${TESTDIR}/tests/tinyGraphBFSTest.o: tests/tinyGraphBFSTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -I. -std=c++11 -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/tinyGraphBFSTest.o tests/tinyGraphBFSTest.cpp


${OBJECTDIR}/Buffer_nomain.o: ${OBJECTDIR}/Buffer.o Buffer.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Buffer.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Buffer_nomain.o Buffer.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Buffer.o ${OBJECTDIR}/Buffer_nomain.o;\
	fi

${OBJECTDIR}/BufferNode_nomain.o: ${OBJECTDIR}/BufferNode.o BufferNode.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/BufferNode.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/BufferNode_nomain.o BufferNode.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/BufferNode.o ${OBJECTDIR}/BufferNode_nomain.o;\
	fi

<<<<<<< HEAD
${OBJECTDIR}/Component_nomain.o: ${OBJECTDIR}/Component.o Component.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Component.o`; \
=======
${OBJECTDIR}/HashTable_nomain.o: ${OBJECTDIR}/HashTable.o HashTable.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/HashTable.o`; \
>>>>>>> 779dac4661bc2ddf5ac78fd0dcc9a2646c710e32
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
<<<<<<< HEAD
	    $(COMPILE.cc) -g -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Component_nomain.o Component.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Component.o ${OBJECTDIR}/Component_nomain.o;\
	fi

${OBJECTDIR}/ComponentCursor_nomain.o: ${OBJECTDIR}/ComponentCursor.o ComponentCursor.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ComponentCursor.o`; \
=======
	    $(COMPILE.cc) -g -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/HashTable_nomain.o HashTable.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/HashTable.o ${OBJECTDIR}/HashTable_nomain.o;\
	fi

${OBJECTDIR}/Index_nomain.o: ${OBJECTDIR}/Index.o Index.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Index.o`; \
>>>>>>> 779dac4661bc2ddf5ac78fd0dcc9a2646c710e32
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
<<<<<<< HEAD
	    $(COMPILE.cc) -g -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ComponentCursor_nomain.o ComponentCursor.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/ComponentCursor.o ${OBJECTDIR}/ComponentCursor_nomain.o;\
	fi

${OBJECTDIR}/HashTable_nomain.o: ${OBJECTDIR}/HashTable.o HashTable.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/HashTable.o`; \
=======
	    $(COMPILE.cc) -g -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Index_nomain.o Index.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Index.o ${OBJECTDIR}/Index_nomain.o;\
	fi

${OBJECTDIR}/IndexNode_nomain.o: ${OBJECTDIR}/IndexNode.o IndexNode.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/IndexNode.o`; \
>>>>>>> 779dac4661bc2ddf5ac78fd0dcc9a2646c710e32
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
<<<<<<< HEAD
	    $(COMPILE.cc) -g -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/HashTable_nomain.o HashTable.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/HashTable.o ${OBJECTDIR}/HashTable_nomain.o;\
	fi

${OBJECTDIR}/Index_nomain.o: ${OBJECTDIR}/Index.o Index.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Index.o`; \
=======
	    $(COMPILE.cc) -g -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/IndexNode_nomain.o IndexNode.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/IndexNode.o ${OBJECTDIR}/IndexNode_nomain.o;\
	fi

${OBJECTDIR}/bfs_nomain.o: ${OBJECTDIR}/bfs.o bfs.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/bfs.o`; \
>>>>>>> 779dac4661bc2ddf5ac78fd0dcc9a2646c710e32
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
<<<<<<< HEAD
	    $(COMPILE.cc) -g -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Index_nomain.o Index.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Index.o ${OBJECTDIR}/Index_nomain.o;\
	fi

${OBJECTDIR}/IndexNode_nomain.o: ${OBJECTDIR}/IndexNode.o IndexNode.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/IndexNode.o`; \
=======
	    $(COMPILE.cc) -g -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/bfs_nomain.o bfs.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/bfs.o ${OBJECTDIR}/bfs_nomain.o;\
	fi

${OBJECTDIR}/bucket_nomain.o: ${OBJECTDIR}/bucket.o bucket.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/bucket.o`; \
>>>>>>> 779dac4661bc2ddf5ac78fd0dcc9a2646c710e32
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
<<<<<<< HEAD
	    $(COMPILE.cc) -g -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/IndexNode_nomain.o IndexNode.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/IndexNode.o ${OBJECTDIR}/IndexNode_nomain.o;\
	fi

${OBJECTDIR}/bfs_nomain.o: ${OBJECTDIR}/bfs.o bfs.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/bfs.o`; \
=======
	    $(COMPILE.cc) -g -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/bucket_nomain.o bucket.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/bucket.o ${OBJECTDIR}/bucket_nomain.o;\
	fi

${OBJECTDIR}/cc_nomain.o: ${OBJECTDIR}/cc.o cc.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/cc.o`; \
>>>>>>> 779dac4661bc2ddf5ac78fd0dcc9a2646c710e32
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
<<<<<<< HEAD
	    $(COMPILE.cc) -g -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/bfs_nomain.o bfs.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/bfs.o ${OBJECTDIR}/bfs_nomain.o;\
	fi

${OBJECTDIR}/bucket_nomain.o: ${OBJECTDIR}/bucket.o bucket.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/bucket.o`; \
=======
	    $(COMPILE.cc) -g -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/cc_nomain.o cc.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/cc.o ${OBJECTDIR}/cc_nomain.o;\
	fi

${OBJECTDIR}/graphLibrary_nomain.o: ${OBJECTDIR}/graphLibrary.o graphLibrary.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/graphLibrary.o`; \
>>>>>>> 779dac4661bc2ddf5ac78fd0dcc9a2646c710e32
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
<<<<<<< HEAD
	    $(COMPILE.cc) -g -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/bucket_nomain.o bucket.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/bucket.o ${OBJECTDIR}/bucket_nomain.o;\
	fi

${OBJECTDIR}/graphLibrary_nomain.o: ${OBJECTDIR}/graphLibrary.o graphLibrary.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/graphLibrary.o`; \
=======
	    $(COMPILE.cc) -g -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/graphLibrary_nomain.o graphLibrary.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/graphLibrary.o ${OBJECTDIR}/graphLibrary_nomain.o;\
	fi

${OBJECTDIR}/main_nomain.o: ${OBJECTDIR}/main.o main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/main.o`; \
>>>>>>> 779dac4661bc2ddf5ac78fd0dcc9a2646c710e32
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
<<<<<<< HEAD
	    $(COMPILE.cc) -g -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/graphLibrary_nomain.o graphLibrary.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/graphLibrary.o ${OBJECTDIR}/graphLibrary_nomain.o;\
	fi

${OBJECTDIR}/main_nomain.o: ${OBJECTDIR}/main.o main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/main.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main_nomain.o main.cpp;\
	else  \
=======
	    $(COMPILE.cc) -g -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main_nomain.o main.cpp;\
	else  \
>>>>>>> 779dac4661bc2ddf5ac78fd0dcc9a2646c710e32
	    ${CP} ${OBJECTDIR}/main.o ${OBJECTDIR}/main_nomain.o;\
	fi

${OBJECTDIR}/queue_nomain.o: ${OBJECTDIR}/queue.o queue.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/queue.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/queue_nomain.o queue.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/queue.o ${OBJECTDIR}/queue_nomain.o;\
	fi

${OBJECTDIR}/scc_nomain.o: ${OBJECTDIR}/scc.o scc.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/scc.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/scc_nomain.o scc.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/scc.o ${OBJECTDIR}/scc_nomain.o;\
	fi

${OBJECTDIR}/stack_nomain.o: ${OBJECTDIR}/stack.o stack.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/stack.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/stack_nomain.o stack.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/stack.o ${OBJECTDIR}/stack_nomain.o;\
	fi

${OBJECTDIR}/updateIndex_nomain.o: ${OBJECTDIR}/updateIndex.o updateIndex.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/updateIndex.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/updateIndex_nomain.o updateIndex.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/updateIndex.o ${OBJECTDIR}/updateIndex_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${TESTDIR}/TestFiles/f2 || true; \
	    ${TESTDIR}/TestFiles/f1 || true; \
	else  \
	    ./${TEST} || true; \
	fi

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/shortestpathproblem

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
