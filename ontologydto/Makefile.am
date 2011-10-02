SUBDIRS = src

lib_LTLIBRARIES = lib_protolayer_ontologydto.la

lib_protolayer_ontologydto_la_SOURCES = \
src/protolayer/ontologydto/AssociationDTO.cpp \
src/protolayer/ontologydto/DomainDTO.cpp \
src/protolayer/ontologydto/EndDTO.cpp \
src/protolayer/ontologydto/Exception.cpp \
src/protolayer/ontologydto/GeneralisationDTO.cpp \
src/protolayer/ontologydto/TypeDTO.cpp

DEFS = \
-I../util/src \
-I../common/src \
-I../xml/src \
-I../iostream/src \
-I../concurrency/src \
-I../ontologydto/src \
-I../logger/src \
-I../pooling/src

check_PROGRAMS = unit_test system_test

unit_test_SOURCES = \
test/src/protolayer/UnitTest.cpp

unit_test_LDADD = \
../ontologydto/lib_protolayer_ontologydto.la \
../workflow/lib_protolayer_workflow.la \
../concurrency/lib_protolayer_concurrency.la \
../iostream/lib_protolayer_iostream.la \
../iostream/lib_protolayer_iostream.la \
../xml/lib_protolayer_xml.la \
../common/lib_protolayer_common.la \
../util/lib_protolayer_util.la

system_test_SOURCES = \
test/src/protolayer/SystemTest.cpp

system_test_LDADD = \
../ontologydto/lib_protolayer_ontologydto.la \
../workflow/lib_protolayer_workflow.la \
../concurrency/lib_protolayer_concurrency.la \
../iostream/lib_protolayer_iostream.la \
../xml/lib_protolayer_xml.la \
../common/lib_protolayer_common.la \
../util/lib_protolayer_util.la
