lib_LTLIBRARIES = lib_protolayer_publishingservice.la

lib_protolayer_publishingservice_la_SOURCES = \
src/protolayer/publishingservice/Configuration.cpp \
src/protolayer/publishingservice/Exception.cpp \
src/protolayer/publishingservice/Service.cpp

DEFS = -I../util/src \
-I../logger/src \
-I../concurrency/src \
-I../naming/src \
-I../common/src \
-I../iostream/src \
-I../xml/src \
-I../net/src \
-I../ontology/src \
-I../ontologydto/src \
-I../assembly/src \
-I../nameservice/src \
-I../containerservice/src \
-I../publishingservice/src \
-I../pooling/src \
-I../server/src

LIBS = \
../common/lib_protolayer_common.la \
../pooling/lib_protolayer_pooling.la \
../concurrency/lib_protolayer_concurrency.la \
../nameservice/lib_protolayer_nameservice.la \
../naming/lib_protolayer_naming.la \
../containerservice/lib_protolayer_containerservice.la \
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
../pooling/lib_protolayer_pooling.la \
../concurrency/lib_protolayer_concurrency.la \
../nameservice/lib_protolayer_nameservice.la \
../naming/lib_protolayer_naming.la \
../containerservice/lib_protolayer_containerservice.la \
../publishingservice/lib_protolayer_publishingservice.la \
../server/lib_protolayer_server.la \
../iostream/lib_protolayer_iostream.la \
../xml/lib_protolayer_xml.la \
../util/lib_protolayer_util.la \
../logger/lib_protolayer_logger.la

start-server:
	./techserver&

start-client:
	./techclient