SUBDIRS = src

lib_LTLIBRARIES = lib_protolayer_reflection.la

lib_protolayer_reflection_la_SOURCES = \
src/protolayer/reflection/TypeName.cpp

check_PROGRAMS = unit_test system_test

unit_test_SOURCES = \
test/src/protolayer/UnitTest.cpp

unit_test_LDADD = \
../util/lib_protolayer_util.la
