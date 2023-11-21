QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    interface.cpp \
    mymat.cpp

HEADERS += \
    interface.h \
    mymat.h

FORMS += \
    interface.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

#Include OpenCV libs
macx: LIBS += -L$$PWD/../../../../../../usr/local/lib/ -lopencv_core.4.8.1 \
                                                       -lopencv_calib3d.4.8.1 \
                                                       -lopencv_dnn.4.8.1 \
                                                       -lopencv_features2d.4.8.1 \
                                                       -lopencv_flann.4.8.1 \
                                                       -lopencv_gapi.4.8.1 \
                                                       -lopencv_highgui.4.8.1 \
                                                       -lopencv_imgcodecs.4.8.1 \
                                                       -lopencv_imgproc.4.8.1 \
                                                       -lopencv_ml.4.8.1 \
                                                       -lopencv_objdetect.4.8.1 \
                                                       -lopencv_photo.4.8.1 \
                                                       -lopencv_stitching.4.8.1 \
                                                       -lopencv_video.4.8.1 \
                                                       -lopencv_videoio.4.8.1

INCLUDEPATH += $$PWD/../../../../../../usr/local/include/opencv4
DEPENDPATH += $$PWD/../../../../../../usr/local/include/opencv4
