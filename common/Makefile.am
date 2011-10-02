SUBDIRS = src

lib_LTLIBRARIES = lib_protolayer_common.la

lib_protolayer_common_la_SOURCES = \
src/protolayer/Exception.cpp \
src/protolayer/ConceptInstance.cpp \
src/protolayer/RootConceptInstance.cpp \
src/protolayer/ImmutableConceptInstance.cpp \
src/protolayer/TechniqueService.cpp

DEFS = -I../util/src -I../iostream/src -I../net/src

LIBS = \
../util/lib_protolayer_util.la