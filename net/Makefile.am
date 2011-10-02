lib_LTLIBRARIES = lib_protolayer_net.la

lib_protolayer_net_la_SOURCES = \
src/protolayer/net/Address.cpp \
src/protolayer/net/ProtocolHeader.cpp \
src/protolayer/net/DataProtocol.cpp \
src/protolayer/net/MessageProtocol.cpp \
src/protolayer/net/Exception.cpp \
src/protolayer/net/ServerSocket.cpp \
src/protolayer/net/Socket.cpp

DEFS = \
-I../iostream/src \
-I../util/src \
-I../common/src \
-I../logger/src \
-I../concurrency/src

LIBS = \
../iostream/lib_protolayer_iostream.la
