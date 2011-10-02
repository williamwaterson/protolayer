SUBDIRS = src

lib_LTLIBRARIES = lib_protolayer_persistence.la

lib_protolayer_persistence_la_SOURCES = \
src/protolayer/persistence/Exception.cpp \
src/protolayer/persistence/DomainManager.cpp \
src/protolayer/persistence/TypeManager.cpp \
src/protolayer/persistence/EndManager.cpp \
src/protolayer/persistence/Facade.cpp \
src/protolayer/persistence/GeneralisationManager.cpp \
src/protolayer/persistence/AssociationManager.cpp \
src/protolayer/persistence/TechniqueManager.cpp \
src/protolayer/persistence/UserManager.cpp \
src/protolayer/persistence/Manager.cpp 

DEFS = \
-I../database/src \
-I../concurrency/src \
-I../pooling/src \
-I../util/src \
-I../dto/src \
-I../logger/src \
-I../common/src \
-I../iostream/src \
-I../ontology/src \
-I../ontologydto/src \
-I../xml/src \
-I../naming/src \
-I/Users/willw/local/mysql/include

#LIBS = \
#/Users/willw/local/mysql/lib/mysql/libmysqlclient.a \
#/Users/willw/local/mysql/lib/mysql/libdbug.a \
#/Users/willw/local/mysql/lib/mysql/libmysys.a \
#/Users/willw/local/mysql/lib/mysql/libmysqlclient.a \
#/Users/willw/local/mysql/lib/mysql/libmystrings.a \
#/Users/willw/local/mysql/lib/mysql/libmysql.imp

check_PROGRAMS = unit_test system_test

unit_test_SOURCES = \
test/src/protolayer/UnitTest.cpp

unit_test_LDADD = \
../common/lib_protolayer_common.la \
../util/lib_protolayer_util.la \
../concurrency/lib_protolayer_concurrency.la

system_test_SOURCES = \
test/src/protolayer/SystemTest.cpp

system_test_LDADD = \
../common/lib_protolayer_common.la \
../util/lib_protolayer_util.la \
../concurrency/lib_protolayer_concurrency.la