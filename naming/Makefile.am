lib_LTLIBRARIES = lib_protolayer_naming.la

lib_protolayer_naming_la_SOURCES = \
src/protolayer/naming/Naming.cpp

DEFS = \
-I../naming/src \
-I../util/src

check_PROGRAMS = unit_test

unit_test_SOURCES = \
test/src/protolayer/UnitTest.cpp

unit_test_LDADD = \
../naming/lib_protolayer_naming.la \
../util/lib_protolayer_util.la
