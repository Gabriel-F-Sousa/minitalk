# cc -o client client.c minitalk.h
# cc -o server_test server.c minitalk.h
make --silent


gnome-terminal -- ./server "FATHER_TERM_PROC=$PPID /bin/bash"
# konsole -e ./server "FATHER_TERM_PROC=$PPID /bin/bash" &

# konsole -e /bin/bash --rcfile <(echo "cd /;ls;echo hi | less")
# sleep 3

AID=$(pidof "server")

# AID=NULL
SEND=$(cat -n text/500w)
#echo $SEND
# echo ./client $AID "$SEND"
echo ./client $AID "$SEND"
./client $AID "$SEND"


#for i in $(seq "40"); do
#	./client $AID "$SEND" &
#     sleep 0.1
#     done
