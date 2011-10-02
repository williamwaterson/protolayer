bin_PROGRAMS = run shutdown

run_SOURCES = \
src/protolayer/node/run.cpp

shutdown_SOURCES = \
src/protolayer/node/shutdown.cpp

DEFS = $(LTDLINCL) $(INCLTDL) \
-I../common/src \
-I../nameservice/src \
-I../naming/src \
-I../util/src \
-I../logger/src \
-I../ontology/src \
-I../ontologydto/src \
-I../iostream/src \
-I../xml/src \
-I../net/src \
-I../server/src \
-I../containerservice/src \
-I../publishingservice/src \
-I../compileservice/src \
-I../assembly/src \
-I../pooling/src \
-I../concurrency/src

LIBS = \
$(LIBLTDL) \
../concurrency/lib_protolayer_concurrency.la \
../pooling/lib_protolayer_pooling.la \
../workflow/lib_protolayer_workflow.la \
../common/lib_protolayer_common.la \
../naming/lib_protolayer_naming.la \
../iostream/lib_protolayer_iostream.la \
../server/lib_protolayer_server.la \
../nameservice/lib_protolayer_nameservice.la \
../compileservice/lib_protolayer_compileservice.la \
../containerservice/lib_protolayer_containerservice.la \
../publishingservice/lib_protolayer_publishingservice.la \
../ontology/lib_protolayer_ontology.la \
../ontologydto/lib_protolayer_ontologydto.la \
../net/lib_protolayer_net.la \
../util/lib_protolayer_util.la \
../logger/lib_protolayer_logger.la \
../xml/lib_protolayer_xml.la \
../assembly/lib_protolayer_assembly.la

check_PROGRAMS = unit_test system_test

unit_test_SOURCES = \
test/src/protolayer/UnitTest.cpp

unit_test_LDADD = \
../common/lib_protolayer_common.la \
../naming/lib_protolayer_naming.la \
../iostream/lib_protolayer_iostream.la \
../server/lib_protolayer_server.la \
../compileservice/lib_protolayer_compileservice.la \
../containerservice/lib_protolayer_containerservice.la \
../publishingservice/lib_protolayer_publishingservice.la \
../ontology/lib_protolayer_ontology.la \
../ontologydto/lib_protolayer_ontologydto.la \
../net/lib_protolayer_net.la \
../util/lib_protolayer_util.la \
../logger/lib_protolayer_logger.la \
../xml/lib_protolayer_xml.la \
../assembly/lib_protolayer_assembly.la

system_test_SOURCES = \
test/src/protolayer/SystemTest.cpp

system_test_LDADD = \
../common/lib_protolayer_common.la \
../nameservice/lib_protolayer_nameservice.la \
../iostream/lib_protolayer_iostream.la \
../server/lib_protolayer_server.la \
../compileservice/lib_protolayer_compileservice.la \
../containerservice/lib_protolayer_containerservice.la \
../publishingservice/lib_protolayer_publishingservice.la \
../ontology/lib_protolayer_ontology.la \
../net/lib_protolayer_net.la \
../util/lib_protolayer_util.la \
../logger/lib_protolayer_logger.la \
../xml/lib_protolayer_xml.la \
../assembly/lib_protolayer_assembly.la

