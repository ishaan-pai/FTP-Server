# FTP-Server
One of my first ever projects done outside of school where I learn everything about it myself.

Contains Two Files so far:
- client.cpp
- server.cpp

client.cpp:
client program to connect to a server. Currently connects to the test server "server.cpp" on localhost 127.0.0.1 on port 2121 however the goal is for it to be able to connect to any FTP server as long as we have the IP, connecting on port 21. Since this is to be an FTP client the goal will be to push this to be able to make a sign in/authentification in some way with the FTP server, as well as making file upload and download to the server possible.

server.cpp:
server program for the client to contact. Currently the program allows the client program to connect to it and is hosted on the localhost 127.0.0.1 with port 2121. While this likely won't be updated as much, it will be used to test some of the most important features. These features are server side sign-in, file upload and storage, and file download to the client server. So far none of these have been implemented however hopefully in due time they will be.

One of the biggest goals was to use this project to learn a multitude of skills, including client/server handshakes, basic networking fundamentals, git/github, and C++. This has served so far as a good example for these things even if I don't fully understand all the code Im using yet.
