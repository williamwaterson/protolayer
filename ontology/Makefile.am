SUBDIRS = src

lib_LTLIBRARIES = lib_protolayer_ontology.la

lib_protolayer_ontology_la_SOURCES = \
src/protolayer/ontology/Association.cpp \
src/protolayer/ontology/Domain.cpp \
src/protolayer/ontology/DomainDependency.cpp \
src/protolayer/ontology/End.cpp \
src/protolayer/ontology/Exception.cpp \
src/protolayer/ontology/Generalisation.cpp \
src/protolayer/ontology/Ontology.cpp \
src/protolayer/ontology/Type.cpp \
src/protolayer/ontology/TypeDependency.cpp \
src/protolayer/ontology/TypeLayer.cpp \
src/protolayer/ontology/TypeStack.cpp \
src/protolayer/ontology/TypeStructure.cpp

DEFS = \
-I../util/src \
-I../concurrency/src \
-I../pooling/src \
-I../naming/src \
-I../common/src \
-I../xml/src \
-I../ontology/src \
-I../iostream/src \
-I../ontologydto/src \
-I../logger/src

check_PROGRAMS = unit_test system_test

unit_test_SOURCES = \
test/src/protolayer/UnitTest.cpp

unit_test_LDADD = \
../ontology/lib_protolayer_ontology.la \
../concurrency/lib_protolayer_concurrency.la \
../naming/lib_protolayer_naming.la \
../workflow/lib_protolayer_workflow.la \
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
../naming/lib_protolayer_naming.la \
../workflow/lib_protolayer_workflow.la \
../ontologydto/lib_protolayer_ontologydto.la \
../iostream/lib_protolayer_iostream.la \
../xml/lib_protolayer_xml.la \
../common/lib_protolayer_common.la \
../util/lib_protolayer_util.la

test: check
	./unit_test