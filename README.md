# FOUR PLAYER CHESS GAME

### DISCLAIMER
As our team mainly used Apple devices to develop this app, we weren't able to test the code on a Windows device. As a result, the graphics and the text might not be fully shown on a Windows machine. 

We highly suggest you to use an Apple device (Intel or Apple Silicon doesn't matter) to ensure maximum performance. 

## How to run? 
This code comes with two different Qt Projects: ChessGame and ChessClient. You will be able to run ChessGame without the Server, however, you'll have to play locally. In order to play with different computers: 
1) Run ChessServer.  ChessServer assumes port 1214 is available. If not, it'll give an error, but won't quit the program. You need to manually edit the port number so that it works. 
2) Run ChessClient
3) Click on Online Game
4) If you're running ChessGame on the same device as you run the ChessServer, put in 127.0.0.1 as the IP address. Otherwise, put in the IP address of the device. 
5) To the port screen, put 1214 (or if you've edited the port, put in that)
6) If you're the first player connecting to the server, you'll be asked if you want to put any bots to the game. THIS IS THE ONLY POINT WHERE YOU CAN ADD BOTS TO AN ONLINE GAME.
7) For other clients, repeat the steps 4-5. 
8) Once the player count is 4, the game will start. 

If you want to test the logic (no networking) 
1) Run ChessClient
2) Click on Online Game
3) You'll be asked if you want to put any bots to the game. 
4) You'll be greeted with the chess board.
