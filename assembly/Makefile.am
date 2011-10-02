SUBDIRS = src

lib_LTLIBRARIES = lib_protolayer_assembly.la

lib_protolayer_assembly_la_SOURCES = \
src/protolayer/assembly/Assembly.cpp \
src/protolayer/assembly/Domain.cpp \
src/protolayer/assembly/DomainDependency.cpp \
src/protolayer/assembly/Instance.cpp \
src/protolayer/assembly/InstanceDependency.cpp \
src/protolayer/assembly/Layer.cpp \
src/protolayer/assembly/Reference.cpp \
src/protolayer/assembly/Exception.cpp \
src/protolayer/assembly/action/CreateInstance.cpp \
src/protolayer/assembly/action/DeleteInstance.cpp \
src/protolayer/assembly/action/CreateReference.cpp \
src/protolayer/assembly/action/DeleteReference.cpp

DEFS = \
-I../common/src \
-I../concurrency/src \
-I../pooling/src \
-I../util/src \
-I../naming/src \
-I../iostream/src \
-I../net/src \
-I../xml/src \
-I../ontology/src \
-I../ontologydto/src \
-I../assembly/src \
-I../workflow/src \
-I../logger/src

check_PROGRAMS = unit_test system_test

unit_test_SOURCES = \
test/src/protolayer/UnitTest.cpp

unit_test_LDADD = \
../iostream/lib_protolayer_iostream.la \
../concurrency/lib_protolayer_concurrency.la \
../assembly/lib_protolayer_assembly.la \
../naming/lib_protolayer_naming.la \
../common/lib_protolayer_common.la \
../ontology/lib_protolayer_ontology.la \
../ontologydto/lib_protolayer_ontologydto.la \
../xml/lib_protolayer_xml.la \
../workflow/lib_protolayer_workflow.la \
../util/lib_protolayer_util.la

system_test_SOURCES = \
test/src/protolayer/SystemTest.cpp

system_test_LDADD = \
../iostream/lib_protolayer_iostream.la \
../common/lib_protolayer_common.la \
../assembly/lib_protolayer_assembly.la \
../ontology/lib_protolayer_ontology.la \
../ontologydto/lib_protolayer_ontologydto.la \
../xml/lib_protolayer_xml.la \
../workflow/lib_protolayer_workflow.la \
../util/lib_protolayer_util.la

test: check
	./unit_test