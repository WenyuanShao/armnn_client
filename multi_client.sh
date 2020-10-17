#!/bin/sh

sudo killall armnn_*
if [ ! -d "logs" ]; then
	mkdir logs
fi
cd logs
rm -rf *
cd ..

python start_client.py \
		-s 10.10.1.2 \
		-p 11211 \
		--nb_cores $1 \
		--nb_request 10 \
		--nb_client $2 \
		--first_client_port 11211 \
