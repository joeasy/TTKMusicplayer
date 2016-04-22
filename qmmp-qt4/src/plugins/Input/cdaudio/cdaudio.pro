include(../../plugins.pri)

HEADERS += decodercdaudiofactory.h \
           decoder_cdaudio.h

SOURCES += decoder_cdaudio.cpp \
           decodercdaudiofactory.cpp

INCLUDEPATH += ../../../ \
                      $$EXTRA_PREFIX/libcddb/include \
                      $$EXTRA_PREFIX/libcdio/include \
                      $$EXTRA_PREFIX/libcdio_paranoia/include

CONFIG += warn_on \
plugin \
link_pkgconfig
TEMPLATE = lib

TARGET =$$PLUGINS_PREFIX/Input/cdaudio

unix {
    QMAKE_LIBDIR += ../../../../lib
      LIBS += -L$$EXTRA_PREFIX/libcdio/lib -lcdio \
              -L$$EXTRA_PREFIX/libcdio_paranoia/lib -lcdio_paranoia -lcdio_cdda \
              -lqmmp
    isEmpty(LIB_DIR) {
        LIB_DIR = /lib
    }
    target.path = $$LIB_DIR/qmmp/Input
    QMAKE_CLEAN =$$PLUGINS_PREFIX/Input/libcdaudio.so
    INSTALLS += target
}

win32 {
  HEADERS += ../../../../src/qmmp/metadatamodel.h \
               ../../../../src/qmmp/decoderfactory.h
  QMAKE_LIBDIR += ../../../../bin
  gcc{
      LIBS += -LD:/Qt/Workspace/qmmp_all/gcc/libcdio/lib -lcdio \
              -LD:/Qt/Workspace/qmmp_all/gcc/libcdio_paranoia/lib -lcdio_paranoia -lcdio_cdda \
              -lqmmp0 -lm -lwinmm -mwindows -liconv -lcddb -lws2_32
  }
#  LIBS += -lqmmp0 -lcdio -lcdio_paranoia -lcdio_cdda  -lm -lwinmm -mwindows -liconv -lcddb -lws2_32
}