lib_LTLIBRARIES = lib_protolayer_containerservice.la

lib_protolayer_containerservice_la_SOURCES = \
src/protolayer/containerservice/Client.cpp \
src/protolayer/containerservice/RootConceptInstanceImpl.cpp \
src/protolayer/containerservice/ImmutableConceptInstanceImpl.cpp \
src/protolayer/containerservice/Configuration.cpp \
src/protolayer/containerservice/Exception.cpp \
src/protolayer/containerservice/Service.cpp

DEFS = -I../util/src \
-I../logger/src \
-I../naming/src \
-I../common/src \
-I../concurrency/src \
-I../iostream/src \
-I../xml/src \
-I../net/src \
-I../ontology/src \
-I../ontologydto/src \
-I../assembly/src \
-I../nameservice/src \
-I../containerservice/src \
-I../pooling/src \
-I../server/src

LIBS = \
../common/lib_protolayer_common.la \
../nameservice/lib_protolayer_nameservice.la \
../concurrency/lib_protolayer_concurrency.la \
../naming/lib_protolayer_naming.la \
../iostream/lib_protolayer_iostream.la \
../ontology/lib_protolayer_ontology.la \
../assembly/lib_protolayer_assembly.la \
../server/lib_protolayer_server.la \
../net/lib_protolayer_net.la \
../util/lib_protolayer_util.la \
../logger/lib_protolayer_logger.la \
../xml/lib_protolayer_xml.la

check_PROGRAMS = unit_test

unit_test_SOURCES = \
tests/src/protolayer/UnitTest.cpp

unit_test_LDADD = \
../ontology/lib_protolayer_ontology.la \
../concurrency/lib_protolayer_concurrency.la \
../nameservice/lib_protolayer_nameservice.la \
../containerservice/lib_protolayer_containerservice.la \
../server/lib_protolayer_server.la \
../iostream/lib_protolayer_iostream.la \
../xml/lib_protolayer_xml.la \
../util/lib_protolayer_util.la \
../logger/lib_protolayer_logger.la

start-server:
	./techserver&

start-client:
	./techclient