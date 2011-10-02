SUBDIRS = src

lib_LTLIBRARIES = lib_protolayer_serialisation.la

lib_protolayer_serialisation_la_SOURCES = \
src/protolayer/serialisation/Exception.cpp \
src/protolayer/serialisation/Serialiser.cpp 

DEFS = \
-I../util/src \
-I../common/src \
-I../iostream/src \
-I../logger/src \
-I../concurrency/src

check_PROGRAMS = unit_test system_test

unit_test_SOURCES = \
test/src/protolayer/UnitTest.cpp

unit_test_LDADD = \
../common/lib_protolayer_common.la \
../util/lib_protolayer_util.la

system_test_SOURCES = \
test/src/protolayer/SystemTest.cpp

system_test_LDADD = \
../common/lib_protolayer_common.la \
../util/lib_protolayer_util.la
