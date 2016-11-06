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
	${OBJECTDIR}/bfs.o \
	${OBJECTDIR}/buffer.o \
	${OBJECTDIR}/index.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/nodeIndex.o \
	${OBJECTDIR}/nodeList.o \
	${OBJECTDIR}/queue.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f1
<<<<<<< HEAD

# Test Object Files
TESTOBJECTFILES= \
	${TESTDIR}/tests/newsimpletest.o
=======
>>>>>>> 0438304ad6ae3a024f42f2b7a7f30f84ef821c12

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
${OBJECTDIR}/buffer.o: buffer.cpp
=======
${OBJECTDIR}/bfs.o: bfs.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/bfs.o bfs.cpp

${OBJECTDIR}/buffer.o: buffer.cpp 
>>>>>>> 0438304ad6ae3a024f42f2b7a7f30f84ef821c12
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/buffer.o buffer.cpp

<<<<<<< HEAD
${OBJECTDIR}/index.o: index.cpp
=======
${OBJECTDIR}/index.o: index.cpp 
>>>>>>> 0438304ad6ae3a024f42f2b7a7f30f84ef821c12
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/index.o index.cpp

<<<<<<< HEAD
${OBJECTDIR}/main.o: main.cpp
=======
${OBJECTDIR}/main.o: main.cpp 
>>>>>>> 0438304ad6ae3a024f42f2b7a7f30f84ef821c12
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

<<<<<<< HEAD
${OBJECTDIR}/nodeIndex.o: nodeIndex.cpp
=======
${OBJECTDIR}/nodeIndex.o: nodeIndex.cpp 
>>>>>>> 0438304ad6ae3a024f42f2b7a7f30f84ef821c12
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/nodeIndex.o nodeIndex.cpp

<<<<<<< HEAD
${OBJECTDIR}/nodeList.o: nodeList.cpp
=======
${OBJECTDIR}/nodeList.o: nodeList.cpp 
>>>>>>> 0438304ad6ae3a024f42f2b7a7f30f84ef821c12
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/nodeList.o nodeList.cpp

<<<<<<< HEAD
${OBJECTDIR}/queue.o: queue.cpp
=======
${OBJECTDIR}/queue.o: queue.cpp 
>>>>>>> 0438304ad6ae3a024f42f2b7a7f30f84ef821c12
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/queue.o queue.cpp

# Subprojects
.build-subprojects:

# Build Test Targets
<<<<<<< HEAD
.build-tests-conf: .build-tests-subprojects .build-conf ${TESTFILES}
.build-tests-subprojects:

${TESTDIR}/TestFiles/f1: ${TESTDIR}/tests/newsimpletest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc} -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS}   
=======
.build-tests-conf: .build-conf ${TESTFILES}
${TESTDIR}/TestFiles/f1: ${TESTDIR}/tests/newsimpletest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS} 
>>>>>>> 0438304ad6ae3a024f42f2b7a7f30f84ef821c12


${TESTDIR}/tests/newsimpletest.o: tests/newsimpletest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -I. -std=c++11 -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/newsimpletest.o tests/newsimpletest.cpp


${OBJECTDIR}/bfs_nomain.o: ${OBJECTDIR}/bfs.o bfs.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/bfs.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/bfs_nomain.o bfs.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/bfs.o ${OBJECTDIR}/bfs_nomain.o;\
	fi

${OBJECTDIR}/buffer_nomain.o: ${OBJECTDIR}/buffer.o buffer.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/buffer.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/buffer_nomain.o buffer.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/buffer.o ${OBJECTDIR}/buffer_nomain.o;\
	fi

${OBJECTDIR}/index_nomain.o: ${OBJECTDIR}/index.o index.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/index.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/index_nomain.o index.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/index.o ${OBJECTDIR}/index_nomain.o;\
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
	    ${CP} ${OBJECTDIR}/main.o ${OBJECTDIR}/main_nomain.o;\
	fi

${OBJECTDIR}/nodeIndex_nomain.o: ${OBJECTDIR}/nodeIndex.o nodeIndex.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/nodeIndex.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/nodeIndex_nomain.o nodeIndex.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/nodeIndex.o ${OBJECTDIR}/nodeIndex_nomain.o;\
	fi

${OBJECTDIR}/nodeList_nomain.o: ${OBJECTDIR}/nodeList.o nodeList.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/nodeList.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/nodeList_nomain.o nodeList.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/nodeList.o ${OBJECTDIR}/nodeList_nomain.o;\
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

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
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
