lib_LTLIBRARIES = lib_protolayer_registration.la

lib_protolayer_registration_la_SOURCES = \
src/protolayer/registration/Client.cpp \
src/protolayer/registration/Exception.cpp \
src/protolayer/registration/Service.cpp \
src/protolayer/registration/UserService.cpp \
src/protolayer/registration/TypeService.cpp \
src/protolayer/registration/EndService.cpp \
src/protolayer/registration/GeneralisationService.cpp \
src/protolayer/registration/AssociationService.cpp \
src/protolayer/registration/DomainService.cpp \
src/protolayer/registration/TechniqueService.cpp \
src/protolayer/registration/ServiceProtocol.cpp

DEFS = \
-I../dto/src \
-I../concurrency/src \
-I../pooling/src \
-I../ontologydto/src \
-I../util/src \
-I../naming/src \
-I../common/src \
-I../logger/src \
-I../database/src \
-I../iostream/src \
-I../xml/src \
-I../net/src \
-I../server/src \
-I../ontology/src \
-I../persistence/src \
-I/usr/local/mysql/include

LIBS = ../ontologydto/lib_protolayer_ontologydto.la
