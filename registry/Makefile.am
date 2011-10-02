bin_PROGRAMS = run shutdown setup_database.app

run_SOURCES = src/protolayer/registry/run.cpp

shutdown_SOURCES = src/protolayer/registry/shutdown.cpp

setup_database_app_SOURCES = src/protolayer/registry/Setup.cpp

DEFS = \
-I../ontologydto/src \
-I../dto/src \
-I../database/src \
-I../util/src \
-I../naming/src \
-I../common/src \
-I../logger/src \
-I../iostream/src \
-I../xml/src \
-I../net/src \
-I../server/src \
-I../registration/src \
-I../relayservice/src \
-I../ontology/src \
-I../concurrency/src \
-I../pooling/src \
-I../persistence/src \
-I/Users/willw/local/mysql/include

LIBS = \
../persistence/lib_protolayer_persistence.la \
../concurrency/lib_protolayer_concurrency.la \
../pooling/lib_protolayer_pooling.la \
../workflow/lib_protolayer_workflow.la \
../ontology/lib_protolayer_ontology.la \
../database/lib_protolayer_database.la \
../ontologydto/lib_protolayer_ontologydto.la \
../dto/lib_protolayer_dto.la \
../iostream/lib_protolayer_iostream.la \
../server/lib_protolayer_server.la \
../registration/lib_protolayer_registration.la \
../relayservice/lib_protolayer_relayservice.la \
../net/lib_protolayer_net.la \
../util/lib_protolayer_util.la \
../naming/lib_protolayer_naming.la \
../common/lib_protolayer_common.la \
../logger/lib_protolayer_logger.la \
../xml/lib_protolayer_xml.la

setup_database_app_LDADD = \
/Users/willw/local/mysql/lib/mysql/libmysqlclient.a \
/Users/willw/local/mysql/lib/mysql/libdbug.a \
/Users/willw/local/mysql/lib/mysql/libmysys.a \
/Users/willw/local/mysql/lib/mysql/libmysqlclient.a \
/Users/willw/local/mysql/lib/mysql/libmystrings.a \
../persistence/lib_protolayer_persistence.la \
../pooling/lib_protolayer_pooling.la \
../workflow/lib_protolayer_workflow.la \
../ontology/lib_protolayer_ontology.la \
../database/lib_protolayer_database.la \
../ontologydto/lib_protolayer_ontologydto.la \
../dto/lib_protolayer_dto.la \
../iostream/lib_protolayer_iostream.la \
../server/lib_protolayer_server.la \
../registration/lib_protolayer_registration.la \
../relayservice/lib_protolayer_relayservice.la \
../net/lib_protolayer_net.la \
../util/lib_protolayer_util.la \
../naming/lib_protolayer_naming.la \
../common/lib_protolayer_common.la \
../logger/lib_protolayer_logger.la \
../xml/lib_protolayer_xml.la

check_PROGRAMS = \
unit_test \
system_test

unit_test_SOURCES = \
test/src/protolayer/UnitTest.cpp

unit_test_LDADD = \
../common/lib_protolayer_common.la \
../iostream/lib_protolayer_iostream.la \
../server/lib_protolayer_server.la \
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
../ontology/lib_protolayer_ontology.la \
../ontologydto/lib_protolayer_ontologydto.la \
../net/lib_protolayer_net.la \
../util/lib_protolayer_util.la \
../common/lib_protolayer_common.la \
../logger/lib_protolayer_logger.la \
../xml/lib_protolayer_xml.la \
../assembly/lib_protolayer_assembly.la

test: check
	./setup_database.app
	./unit_test