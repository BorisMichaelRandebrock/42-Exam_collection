#!/bin/bash
# Test script for mini_serv

# Start server
./mini_serv 8080 &
SERVER_PID=$!

# Connect 10 clients
for i in {1..10}; do
    nc -z 127.0.0.1 8080 &
done

# Kill clients abruptly
pkill -f "nc -z 127.0.0.1 8080"

# Check server FDs
lsof -p $SERVER_PID | grep -v "TCP" | grep -v "IPv4"

# Cleanup
kill $SERVER_PID
