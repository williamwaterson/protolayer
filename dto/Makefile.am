SUBDIRS = src

lib_LTLIBRARIES = lib_protolayer_dto.la

lib_protolayer_dto_la_SOURCES = \
src/protolayer/dto/TechniqueDTO.cpp \
src/protolayer/dto/UserDTO.cpp

DEFS = \
-I../util/src \
-I../common/src \
-I../concurrency/src \
-I../xml/src \
-I../iostream/src \
-I../techniquedto/src \
-I../dto/src \
-I../logger/src

check_PROGRAMS = unit_test system_test

unit_test_SOURCES = \
test/src/protolayer/UnitTest.cpp

unit_test_LDADD = \
../ontology/lib_protolayer_ontology.la \
../concurrency/lib_protolayer_concurrency.la \
../ontologydto/lib_protolayer_ontologydto.la \
../iostream/lib_protolayer_iostream.la \
../xml/lib_protolayer_xml.la \
../common/lib_protolayer_common.la \
../util/lib_protolayer_util.la

system_test_SOURCES = \
test/src/protolayer/SystemTest.cpp

system_test_LDADD = \
../ontology/lib_protolayer_ontology.la \
../concurrency/lib_protolayer_concurrency.la \
../ontologydto/lib_protolayer_ontologydto.la \
../iostream/lib_protolayer_iostream.la \
../xml/lib_protolayer_xml.la \
../common/lib_protolayer_common.la \
../util/lib_protolayer_util.la
