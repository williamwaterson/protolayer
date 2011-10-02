lib_LTLIBRARIES = lib_protolayer_compileservice.la

lib_protolayer_compileservice_la_SOURCES = \
src/protolayer/compileservice/Configuration.cpp \
src/protolayer/compileservice/Directory.cpp \
src/protolayer/compileservice/File.cpp \
src/protolayer/compileservice/Project.cpp \
src/protolayer/compileservice/Exception.cpp \
src/protolayer/compileservice/Service.cpp

DEFS = $(LTDLINCL) $(INCLTDL) \
-I../nameservice/src \
-I../naming/src \
-I../common/src \
-I../logger/src \
-I../containerservice/src \
-I../assembly/src \
-I../util/src \
-I../iostream/src \
-I../net/src \
-I../server/src \
-I../ontology/src \
-I../xml/src \
-I../concurrency/src \
-I../pooling/src \
-I../ontologydto/src

LIBS = \
$(LIBLTDL) \
../common/lib_protolayer_common.la \
../naming/lib_protolayer_naming.la \
../logger/lib_protolayer_logger.la \
../nameservice/lib_protolayer_nameservice.la \
../concurrency/lib_protolayer_concurrency.la \
../pooling/lib_protolayer_pooling.la \
../iostream/lib_protolayer_iostream.la \
../assembly/lib_protolayer_assembly.la \
../containerservice/lib_protolayer_containerservice.la \
../net/lib_protolayer_net.la \
../ontology/lib_protolayer_ontology.la \
../util/lib_protolayer_util.la \
../xml/lib_protolayer_xml.la \
../server/lib_protolayer_server.la
