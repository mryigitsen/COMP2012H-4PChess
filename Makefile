OUT := chess
ZIP_OUT := chess.zip

CXX := g++
CXXFLAGS := -std=c++11 -Wall -Wextra -pedantic -Iinclude
LDFLAGS :=

ifeq (Windows_NT, $(OS))

RM := del
SRCS := Game.cpp main.cpp Player.cpp Pieces\Piece.cpp Pieces\Bishop.cpp Pieces\King.cpp Pieces\Knight.cpp Pieces\Pawn.cpp Pieces\Queen.cpp Pieces\Rock.cpp
SUBMISSION := Game.cpp main.cpp Player.cpp Pieces\Piece.cpp Pieces\Bishop.cpp Pieces\King.cpp Pieces\Knight.cpp Pieces\Pawn.cpp Pieces\Queen.cpp Pieces\Rock.cpp Game.h Player.h Pieces\Piece.h Pieces\Bishop.h Pieces\King.h Pieces\Knight.h Pieces\Pawn.h Pieces\Queen.h Pieces\Rock.h
ZIP := zip.exe

else

RM := rm -f
SRCS := Game.cpp main.cpp Player.cpp Pieces\Piece.cpp Pieces\Bishop.cpp Pieces\King.cpp Pieces\Knight.cpp Pieces\Pawn.cpp Pieces\Queen.cpp Pieces\Rock.cpp
SUBMISSION := Game.cpp main.cpp Player.cpp Pieces\Piece.cpp Pieces\Bishop.cpp Pieces\King.cpp Pieces\Knight.cpp Pieces\Pawn.cpp Pieces\Queen.cpp Pieces\Rock.cpp Game.h Player.h Pieces\Piece.h Pieces\Bishop.h Pieces\King.h Pieces\Knight.h Pieces\Pawn.h Pieces\Queen.h Pieces\Rock.h
ZIP := zip

endif

OBJS := $(patsubst %.cpp,%.o,$(SRCS))

.PHONY: all
all: $(OUT)


$(OUT): $(OBJS)
	$(CXX) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

$(ZIP_OUT): $(SUBMISSION)
	$(RM) $(ZIP_OUT)
	$(ZIP) $@ $^

.PHONY: clean
clean:
	$(RM) $(OUT) $(OBJS) $(ZIP_OUT)
