#############################################################################
# Makefile for building: printer_core
# Generated by qmake (2.01a) (Qt 4.8.6) on: Thu Aug 25 06:19:19 2016
# Project:  printer_core.pro
# Template: app
# Command: /opt/poky-edison/1.7.3/sysroots/x86_64-pokysdk-linux/usr/bin/qmake -spec /opt/poky-edison/1.7.3/sysroots/core2-32-poky-linux/usr/share/qtopia/mkspecs/linux-g++-32 CONFIG+=debug CONFIG+=declarative_debug -o Makefile printer_core.pro
#############################################################################

####### Compiler, tools and options

CC            = $(OE_QMAKE_CC)
CXX           = $(OE_QMAKE_CXX)
DEFINES       = -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -m32 -pipe $(OE_QMAKE_CFLAGS) -g -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -m32 -pipe $(OE_QMAKE_CXXFLAGS) -g -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/opt/poky-edison/1.7.3/sysroots/core2-32-poky-linux/usr/share/qtopia/mkspecs/linux-g++-32 -I. -I$(OE_QMAKE_INCDIR_QT)/QtCore -I$(OE_QMAKE_INCDIR_QT) -I.
LINK          = $(OE_QMAKE_LINK)
LFLAGS        = -m32 $(OE_QMAKE_LDFLAGS) -Wl,-rpath-link,$(OE_QMAKE_LIBDIR_QT)
LIBS          = $(SUBLIBS)  -L$(OE_QMAKE_LIBDIR_QT) -L/opt/poky-edison/1.7.3/sysroots/core2-32-poky-linux/usr/lib -lmraa -lQtDBusE -lQtXmlE -lQtCoreE -lpthread 
AR            = $(OE_QMAKE_AR) cqs
RANLIB        = 
QMAKE         = /opt/poky-edison/1.7.3/sysroots/x86_64-pokysdk-linux/usr/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = $(OE_QMAKE_STRIP)
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = main.cpp \
		printer_core.cpp moc_printer_core.cpp
OBJECTS       = main.o \
		printer_core.o \
		moc_printer_core.o
DIST          = /opt/poky-edison/1.7.3/sysroots/core2-32-poky-linux/usr/share/qtopia/mkspecs/common/unix.conf \
		/opt/poky-edison/1.7.3/sysroots/core2-32-poky-linux/usr/share/qtopia/mkspecs/common/linux.conf \
		/opt/poky-edison/1.7.3/sysroots/core2-32-poky-linux/usr/share/qtopia/mkspecs/common/gcc-base.conf \
		/opt/poky-edison/1.7.3/sysroots/core2-32-poky-linux/usr/share/qtopia/mkspecs/common/gcc-base-unix.conf \
		/opt/poky-edison/1.7.3/sysroots/core2-32-poky-linux/usr/share/qtopia/mkspecs/common/g++-unix.conf \
		/opt/poky-edison/1.7.3/sysroots/core2-32-poky-linux/usr/share/qtopia/mkspecs/qconfig.pri \
		/opt/poky-edison/1.7.3/sysroots/core2-32-poky-linux/usr/share/qtopia/mkspecs/modules/qt_webkit_version.pri \
		/opt/poky-edison/1.7.3/sysroots/core2-32-poky-linux/usr/share/qtopia/mkspecs/features/qt_functions.prf \
		/opt/poky-edison/1.7.3/sysroots/core2-32-poky-linux/usr/share/qtopia/mkspecs/features/qt_config.prf \
		/opt/poky-edison/1.7.3/sysroots/core2-32-poky-linux/usr/share/qtopia/mkspecs/features/exclusive_builds.prf \
		/opt/poky-edison/1.7.3/sysroots/core2-32-poky-linux/usr/share/qtopia/mkspecs/features/default_pre.prf \
		/opt/poky-edison/1.7.3/sysroots/core2-32-poky-linux/usr/share/qtopia/mkspecs/features/debug.prf \
		/opt/poky-edison/1.7.3/sysroots/core2-32-poky-linux/usr/share/qtopia/mkspecs/features/default_post.prf \
		/opt/poky-edison/1.7.3/sysroots/core2-32-poky-linux/usr/share/qtopia/mkspecs/features/declarative_debug.prf \
		/opt/poky-edison/1.7.3/sysroots/core2-32-poky-linux/usr/share/qtopia/mkspecs/features/shared.prf \
		/opt/poky-edison/1.7.3/sysroots/core2-32-poky-linux/usr/share/qtopia/mkspecs/features/warn_on.prf \
		/opt/poky-edison/1.7.3/sysroots/core2-32-poky-linux/usr/share/qtopia/mkspecs/features/qt.prf \
		/opt/poky-edison/1.7.3/sysroots/core2-32-poky-linux/usr/share/qtopia/mkspecs/features/unix/thread.prf \
		/opt/poky-edison/1.7.3/sysroots/core2-32-poky-linux/usr/share/qtopia/mkspecs/features/moc.prf \
		/opt/poky-edison/1.7.3/sysroots/core2-32-poky-linux/usr/share/qtopia/mkspecs/features/resources.prf \
		/opt/poky-edison/1.7.3/sysroots/core2-32-poky-linux/usr/share/qtopia/mkspecs/features/uic.prf \
		/opt/poky-edison/1.7.3/sysroots/core2-32-poky-linux/usr/share/qtopia/mkspecs/features/yacc.prf \
		/opt/poky-edison/1.7.3/sysroots/core2-32-poky-linux/usr/share/qtopia/mkspecs/features/lex.prf \
		/opt/poky-edison/1.7.3/sysroots/core2-32-poky-linux/usr/share/qtopia/mkspecs/features/include_source_dir.prf \
		printer_core.pro
QMAKE_TARGET  = printer_core
DESTDIR       = 
TARGET        = printer_core

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET):  $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: printer_core.pro  /opt/poky-edison/1.7.3/sysroots/core2-32-poky-linux/usr/share/qtopia/mkspecs/linux-g++-32/qmake.conf /opt/poky-edison/1.7.3/sysroots/core2-32-poky-linux/usr/share/qtopia/mkspecs/common/unix.conf \
		/opt/poky-edison/1.7.3/sysroots/core2-32-poky-linux/usr/share/qtopia/mkspecs/common/linux.conf \
		/opt/poky-edison/1.7.3/sysroots/core2-32-poky-linux/usr/share/qtopia/mkspecs/common/gcc-base.conf \
		/opt/poky-edison/1.7.3/sysroots/core2-32-poky-linux/usr/share/qtopia/mkspecs/common/gcc-base-unix.conf \
		/opt/poky-edison/1.7.3/sysroots/core2-32-poky-linux/usr/share/qtopia/mkspecs/common/g++-unix.conf \
		/opt/poky-edison/1.7.3/sysroots/core2-32-poky-linux/usr/share/qtopia/mkspecs/qconfig.pri \
		/opt/poky-edison/1.7.3/sysroots/core2-32-poky-linux/usr/share/qtopia/mkspecs/modules/qt_webkit_version.pri \
		/opt/poky-edison/1.7.3/sysroots/core2-32-poky-linux/usr/share/qtopia/mkspecs/features/qt_functions.prf \
		/opt/poky-edison/1.7.3/sysroots/core2-32-poky-linux/usr/share/qtopia/mkspecs/features/qt_config.prf \
		/opt/poky-edison/1.7.3/sysroots/core2-32-poky-linux/usr/share/qtopia/mkspecs/features/exclusive_builds.prf \
		/opt/poky-edison/1.7.3/sysroots/core2-32-poky-linux/usr/share/qtopia/mkspecs/features/default_pre.prf \
		/opt/poky-edison/1.7.3/sysroots/core2-32-poky-linux/usr/share/qtopia/mkspecs/features/debug.prf \
		/opt/poky-edison/1.7.3/sysroots/core2-32-poky-linux/usr/share/qtopia/mkspecs/features/default_post.prf \
		/opt/poky-edison/1.7.3/sysroots/core2-32-poky-linux/usr/share/qtopia/mkspecs/features/declarative_debug.prf \
		/opt/poky-edison/1.7.3/sysroots/core2-32-poky-linux/usr/share/qtopia/mkspecs/features/shared.prf \
		/opt/poky-edison/1.7.3/sysroots/core2-32-poky-linux/usr/share/qtopia/mkspecs/features/warn_on.prf \
		/opt/poky-edison/1.7.3/sysroots/core2-32-poky-linux/usr/share/qtopia/mkspecs/features/qt.prf \
		/opt/poky-edison/1.7.3/sysroots/core2-32-poky-linux/usr/share/qtopia/mkspecs/features/unix/thread.prf \
		/opt/poky-edison/1.7.3/sysroots/core2-32-poky-linux/usr/share/qtopia/mkspecs/features/moc.prf \
		/opt/poky-edison/1.7.3/sysroots/core2-32-poky-linux/usr/share/qtopia/mkspecs/features/resources.prf \
		/opt/poky-edison/1.7.3/sysroots/core2-32-poky-linux/usr/share/qtopia/mkspecs/features/uic.prf \
		/opt/poky-edison/1.7.3/sysroots/core2-32-poky-linux/usr/share/qtopia/mkspecs/features/yacc.prf \
		/opt/poky-edison/1.7.3/sysroots/core2-32-poky-linux/usr/share/qtopia/mkspecs/features/lex.prf \
		/opt/poky-edison/1.7.3/sysroots/core2-32-poky-linux/usr/share/qtopia/mkspecs/features/include_source_dir.prf \
		/opt/poky-edison/1.7.3/sysroots/core2-32-poky-linux/usr/lib/libQtDBusE.prl \
		/opt/poky-edison/1.7.3/sysroots/core2-32-poky-linux/usr/lib/libQtXmlE.prl \
		/opt/poky-edison/1.7.3/sysroots/core2-32-poky-linux/usr/lib/libQtCoreE.prl
	$(QMAKE) -spec /opt/poky-edison/1.7.3/sysroots/core2-32-poky-linux/usr/share/qtopia/mkspecs/linux-g++-32 CONFIG+=debug CONFIG+=declarative_debug -o Makefile printer_core.pro
/opt/poky-edison/1.7.3/sysroots/core2-32-poky-linux/usr/share/qtopia/mkspecs/common/unix.conf:
/opt/poky-edison/1.7.3/sysroots/core2-32-poky-linux/usr/share/qtopia/mkspecs/common/linux.conf:
/opt/poky-edison/1.7.3/sysroots/core2-32-poky-linux/usr/share/qtopia/mkspecs/common/gcc-base.conf:
/opt/poky-edison/1.7.3/sysroots/core2-32-poky-linux/usr/share/qtopia/mkspecs/common/gcc-base-unix.conf:
/opt/poky-edison/1.7.3/sysroots/core2-32-poky-linux/usr/share/qtopia/mkspecs/common/g++-unix.conf:
/opt/poky-edison/1.7.3/sysroots/core2-32-poky-linux/usr/share/qtopia/mkspecs/qconfig.pri:
/opt/poky-edison/1.7.3/sysroots/core2-32-poky-linux/usr/share/qtopia/mkspecs/modules/qt_webkit_version.pri:
/opt/poky-edison/1.7.3/sysroots/core2-32-poky-linux/usr/share/qtopia/mkspecs/features/qt_functions.prf:
/opt/poky-edison/1.7.3/sysroots/core2-32-poky-linux/usr/share/qtopia/mkspecs/features/qt_config.prf:
/opt/poky-edison/1.7.3/sysroots/core2-32-poky-linux/usr/share/qtopia/mkspecs/features/exclusive_builds.prf:
/opt/poky-edison/1.7.3/sysroots/core2-32-poky-linux/usr/share/qtopia/mkspecs/features/default_pre.prf:
/opt/poky-edison/1.7.3/sysroots/core2-32-poky-linux/usr/share/qtopia/mkspecs/features/debug.prf:
/opt/poky-edison/1.7.3/sysroots/core2-32-poky-linux/usr/share/qtopia/mkspecs/features/default_post.prf:
/opt/poky-edison/1.7.3/sysroots/core2-32-poky-linux/usr/share/qtopia/mkspecs/features/declarative_debug.prf:
/opt/poky-edison/1.7.3/sysroots/core2-32-poky-linux/usr/share/qtopia/mkspecs/features/shared.prf:
/opt/poky-edison/1.7.3/sysroots/core2-32-poky-linux/usr/share/qtopia/mkspecs/features/warn_on.prf:
/opt/poky-edison/1.7.3/sysroots/core2-32-poky-linux/usr/share/qtopia/mkspecs/features/qt.prf:
/opt/poky-edison/1.7.3/sysroots/core2-32-poky-linux/usr/share/qtopia/mkspecs/features/unix/thread.prf:
/opt/poky-edison/1.7.3/sysroots/core2-32-poky-linux/usr/share/qtopia/mkspecs/features/moc.prf:
/opt/poky-edison/1.7.3/sysroots/core2-32-poky-linux/usr/share/qtopia/mkspecs/features/resources.prf:
/opt/poky-edison/1.7.3/sysroots/core2-32-poky-linux/usr/share/qtopia/mkspecs/features/uic.prf:
/opt/poky-edison/1.7.3/sysroots/core2-32-poky-linux/usr/share/qtopia/mkspecs/features/yacc.prf:
/opt/poky-edison/1.7.3/sysroots/core2-32-poky-linux/usr/share/qtopia/mkspecs/features/lex.prf:
/opt/poky-edison/1.7.3/sysroots/core2-32-poky-linux/usr/share/qtopia/mkspecs/features/include_source_dir.prf:
/opt/poky-edison/1.7.3/sysroots/core2-32-poky-linux/usr/lib/libQtDBusE.prl:
/opt/poky-edison/1.7.3/sysroots/core2-32-poky-linux/usr/lib/libQtXmlE.prl:
/opt/poky-edison/1.7.3/sysroots/core2-32-poky-linux/usr/lib/libQtCoreE.prl:
qmake:  FORCE
	@$(QMAKE) -spec /opt/poky-edison/1.7.3/sysroots/core2-32-poky-linux/usr/share/qtopia/mkspecs/linux-g++-32 CONFIG+=debug CONFIG+=declarative_debug -o Makefile printer_core.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/printer_core1.0.0 || $(MKDIR) .tmp/printer_core1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/printer_core1.0.0/ && $(COPY_FILE) --parents printer_core.h .tmp/printer_core1.0.0/ && $(COPY_FILE) --parents main.cpp printer_core.cpp .tmp/printer_core1.0.0/ && (cd `dirname .tmp/printer_core1.0.0` && $(TAR) printer_core1.0.0.tar printer_core1.0.0 && $(COMPRESS) printer_core1.0.0.tar) && $(MOVE) `dirname .tmp/printer_core1.0.0`/printer_core1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/printer_core1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_printer_core.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_printer_core.cpp
moc_printer_core.cpp: printer_core.h
	$(OE_QMAKE_MOC) $(DEFINES) $(INCPATH) printer_core.h -o moc_printer_core.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all:
compiler_uic_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean 

####### Compile

main.o: main.cpp printer_core.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

printer_core.o: printer_core.cpp printer_core.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o printer_core.o printer_core.cpp

moc_printer_core.o: moc_printer_core.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_printer_core.o moc_printer_core.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

