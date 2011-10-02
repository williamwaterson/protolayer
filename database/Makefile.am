lib_LTLIBRARIES = lib_protolayer_database.la

lib_protolayer_database_la_SOURCES = \
src/protolayer/database/Connection.cpp \
src/protolayer/database/Results.cpp \
src/protolayer/database/Exception.cpp

check_PROGRAMS = unit_test

DEFS = -I../dto/src \
 -I../ontologydto/src \
 -I../logger/src \
 -I../naming/src \
 -I../database/src \
 -I../concurrency/src \
 -I../pooling/src \
 -I../iostream/src \
 -I../xml/src \
 -I../util/src \
 -I../common/src \
 -I/usr/local/mysql/include

unit_test_SOURCES = \
test/src/protolayer/UnitTest.cpp

unit_test_LDADD = \
/usr/local/mysql/lib/libmysqlclient.a \
/usr/local/mysql/lib/libdbug.a \
/usr/local/mysql/lib/libmysys.a \
/usr/local/mysql/lib/libmygcc.a \
/usr/local/mysql/lib/libmysqlclient.a \
/usr/local/mysql/lib/libmystrings.a \
/usr/local/mysql/lib/libz.a \
../database/lib_protolayer_database.la \
../logger/lib_protolayer_logger.la \
../naming/lib_protolayer_naming.la \
../ontology/lib_protolayer_ontology.la \
../dto/lib_protolayer_dto.la \
../concurrency/lib_protolayer_concurrency.la \
../ontologydto/lib_protolayer_ontologydto.la \
../iostream/lib_protolayer_iostream.la \
../xml/lib_protolayer_xml.la \
../common/lib_protolayer_common.la \
../workflow/lib_protolayer_workflow.la \
../util/lib_protolayer_util.la
