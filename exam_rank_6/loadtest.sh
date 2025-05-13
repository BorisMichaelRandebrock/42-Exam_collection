#!/bin/bash
# Heavy-load test script for mini_serv

PORT=8080
MSG_COUNT=3000
CLIENTS=100  # Number of concurrent clients
SERVER_LOG="server.log"

# Start server
./mini_serv $PORT > $SERVER_LOG 2>&1 &
SERVER_PID=$!
sleep 1  # Give server time to start

# Test function for each client
test_client() {
    for ((i=1; i<=$MSG_COUNT; i++)); do
        echo "Message $i from client $1" | nc 127.0.0.1 $PORT
        sleep 0.01  # Small delay to avoid flooding
    done
}

# Launch clients in background
for ((c=1; c<=$CLIENTS; c++)); do
    test_client $c &
    CLIENT_PIDS[$c]=$!
done

# Let test run for a while
sleep 20

# Cleanup
kill ${CLIENT_PIDS[@]} 2>/dev/null
kill $SERVER_PID

# Check for leaks
echo "Checking for leaked FDs..."
lsof -p $SERVER_PID | grep -vE "TCP|IPv4|LISTEN"

echo "Checking server log for errors..."
grep -i "error\|fatal" $SERVER_LOG

echo "Test completed. Server output in $SERVER_LOG"
