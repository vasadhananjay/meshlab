include (../../shared.pri)

HEADERS       = filter_text.h
SOURCES       = filter_text.cpp \
                ../../meshlab/filterparameter.cpp\
		$$GLEWCODE
TARGET        = filter_text
TEMPLATE      = lib
QT           += opengl
CONFIG       += plugin