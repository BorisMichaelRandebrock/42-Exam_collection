# mini_serv — FD Management & Load Test Suite

My solution implements a minimal TCP server requierd by the examen subject `mini_serv`.   
It handles multiple client connections via `select()`, ensures proper file descriptor (FD) closure and robust handling under concurrent load.  
If you are running for the 42 examen, in the main provided (in the examen) you will find a lot of useful code.. (cpy/paste).. compare and find your strategy. 

## ✅ Highlights

- Uses `select()` to monitor active client sockets.
- Cleans up closed sockets to prevent FD leaks.
- Handles simultaneous connections efficiently.
- No memory or FD leaks observed during testing.
- Scripts provided to verify correctness and stress-test the server.

---

## 🧪 Test Scripts

I have created and included two shell scripts to verify functionality and resilience of `mini_serv`:

### `test.sh` — Basic FD Closure Test

Simulates 10 abrupt client connections and disconnections to check for unclosed FDs.

**Usage:**
```bash
chmod +x test.sh
./test.sh
### What it does:

- Starts `mini_serv` on port 8080.  
- Connects 10 dummy clients using `nc`.  
- Abruptly kills all clients with `pkill`.  
- Uses `lsof` to verify that no file descriptors (other than TCP/IP) remain open.  
- Terminates the server process to clean up...
```
### `loadtest.sh` — Heavy Load & Leak Detection   


**Usage:**
```bash
chmod +x loadtest.sh
./loadtest.sh
### What it does:

- Launches `mini_serv` on port 8080, redirecting output to `server.log`.  
- Spawns 100 background client jobs, each sending 3000 messages.  
- Clients send messages using `nc` with short delays to simulate real traffic.  
- After ~20 seconds, all clients are terminated.
```
## 🚀 Run your server manually:
- compile your  server:
```
gcc -Wall -Wextra -Werror location/mini_serv.c -o mini_serv
```
- be aware:   
if you have just copied the initial chunk of main and compile, you will run into a lot of "unused" errors and should compile without flags:
```
gcc location/mini_serv.c -o mini_serv
```
but I advise you to use these flags as often as posssible..    
run the server:
```
./location/mini_serv 1234
``` 
Then run 3 to 4 terminals and run the chat with them:
```
nc 127.0.0.1 1234
```
or:
```
nc localhost 1234
```

### 📝 Notes on Implementation

The implementation is robust & adheres well to the expected behavior:

- Properly closes disconnected sockets (avoids FD leaks).  
- Efficiently uses `select()` to multiplex client communication.  
- Server remains stable even under significant concurrent load.  
- Log output and FD checks confirm clean resource management.



