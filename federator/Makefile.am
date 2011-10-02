bin_PROGRAMS = run shutdown

run_SOURCES = \
src/protolayer/federator/run.cpp

shutdown_SOURCES = \
src/protolayer/federator/shutdown.cpp

DEFS = \
-I../ontologydto/src \
-I../dto/src \
-I../database/src \
-I../concurrency/src \
-I../util/src \
-I../common/src \
-I../logger/src \
-I../iostream/src \
-I../xml/src \
-I../net/src \
-I../server/src \
-I../registration/src \
-I../nameservice/src \
-I../ontology/src \
-I../matchingservice/src \
-I../relayservice/src \
-I/Users/willw/local/mysql/include

LIBS = \
../workflow/lib_protolayer_workflow.la \
../ontology/lib_protolayer_ontology.la \
../database/lib_protolayer_database.la \
../ontologydto/lib_protolayer_ontologydto.la \
../dto/lib_protolayer_dto.la \
../iostream/lib_protolayer_iostream.la \
../server/lib_protolayer_server.la \
../nameservice/lib_protolayer_nameservice.la \
../relayservice/lib_protolayer_relayservice.la \
../matchingservice/lib_protolayer_matchingservice.la \
../registration/lib_protolayer_registration.la \
../net/lib_protolayer_net.la \
../util/lib_protolayer_util.la \
../common/lib_protolayer_common.la \
../logger/lib_protolayer_logger.la \
../xml/lib_protolayer_xml.la

check_PROGRAMS = unit_test system_test

unit_test_SOURCES = \
test/src/protolayer/UnitTest.cpp

unit_test_LDADD = \
../common/lib_protolayer_common.la \
../iostream/lib_protolayer_iostream.la \
../server/lib_protolayer_server.la \
../compileservice/lib_protolayer_compileservice.la \
../containerservice/lib_protolayer_containerservice.la \
../relayservice/lib_protolayer_relayservice.la \
../ontology/lib_protolayer_ontology.la \
../ontologydto/lib_protolayer_ontologydto.la \
../net/lib_protolayer_net.la \
../util/lib_protolayer_util.la \
../common/lib_protolayer_common.la \
../logger/lib_protolayer_logger.la \
../xml/lib_protolayer_xml.la \
../assembly/lib_protolayer_assembly.la

system_test_SOURCES = \
test/src/protolayer/SystemTest.cpp

system_test_LDADD = \
../common/lib_protolayer_common.la \
../iostream/lib_protolayer_iostream.la \
../server/lib_protolayer_server.la \
../compileservice/lib_protolayer_compileservice.la \
../containerservice/lib_protolayer_containerservice.la \
../relayservice/lib_protolayer_relayservice.la \
../ontology/lib_protolayer_ontology.la \
../ontologydto/lib_protolayer_ontologydto.la \
../net/lib_protolayer_net.la \
../util/lib_protolayer_util.la \
../common/lib_protolayer_common.la \
../logger/lib_protolayer_logger.la \
../xml/lib_protolayer_xml.la \
../assembly/lib_protolayer_assembly.la
