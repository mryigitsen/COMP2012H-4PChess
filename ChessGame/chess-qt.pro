QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Game.cpp \
    Player.cpp \
    chessclientobj.cpp \
    chesswidget.cpp \
    main.cpp \
    mainwindow.cpp \
    menuwindow.cpp \
    pieces/Bishop.cpp \
    pieces/King.cpp \
    pieces/Knight.cpp \
    pieces/Pawn.cpp \
    pieces/Piece.cpp \
    pieces/Queen.cpp \
    pieces/Rook.cpp

HEADERS += \
    Game.h \
    Player.h \
    chessclientobj.h \
    chesswidget.h \
    mainwindow.h \
    menuwindow.h \
    pieces/Bishop.h \
    pieces/King.h \
    pieces/Knight.h \
    pieces/Pawn.h \
    pieces/Piece.h \
    pieces/Queen.h \
    pieces/Rook.h

FORMS += \
    mainwindow.ui \
    menuwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    cmake-build-debug/CMakeFiles/clion-log.txt \
    img/Activated_Square.png \
    img/Black_Possible_Move.png \
    img/Black_Square.png \
    img/Player 1/Blue_Bishop.png \
    img/Player 1/Blue_King.png \
    img/Player 1/Blue_Knight.png \
    img/Player 1/Blue_Pawn.png \
    img/Player 1/Blue_Queen.png \
    img/Player 1/Blue_Rook.png \
    img/Player 2/Yellow_Bishop.png \
    img/Player 2/Yellow_King.png \
    img/Player 2/Yellow_Knight.png \
    img/Player 2/Yellow_Pawn.png \
    img/Player 2/Yellow_Queen.png \
    img/Player 2/Yellow_Rook.png \
    img/Player 3/Green_Bishop.png \
    img/Player 3/Green_King.png \
    img/Player 3/Green_Knight.png \
    img/Player 3/Green_Pawn.png \
    img/Player 3/Green_Queen.png \
    img/Player 3/Green_Rook.png \
    img/Player 4/Red_Bishop.png \
    img/Player 4/Red_King.png \
    img/Player 4/Red_Knight.png \
    img/Player 4/Red_Pawn.png \
    img/Player 4/Red_Queen.png \
    img/Player 4/Red_Rook.png \
    img/Player1/Blue_Bishop.png \
    img/Player1/Blue_King.png \
    img/Player1/Blue_Knight.png \
    img/Player1/Blue_Pawn.png \
    img/Player1/Blue_Queen.png \
    img/Player1/Blue_Rook.png \
    img/Player2/Yellow_Bishop.png \
    img/Player2/Yellow_King.png \
    img/Player2/Yellow_Knight.png \
    img/Player2/Yellow_Pawn.png \
    img/Player2/Yellow_Queen.png \
    img/Player2/Yellow_Rook.png \
    img/Player3/Green_Bishop.png \
    img/Player3/Green_King.png \
    img/Player3/Green_Knight.png \
    img/Player3/Green_Pawn.png \
    img/Player3/Green_Queen.png \
    img/Player3/Green_Rook.png \
    img/Player4/Red_Bishop.png \
    img/Player4/Red_King.png \
    img/Player4/Red_Knight.png \
    img/Player4/Red_Pawn.png \
    img/Player4/Red_Queen.png \
    img/Player4/Red_Rook.png \
    img/White_Possible_Move.png \
    img/White_Square.png

RESOURCES += \
    resources.qrc
