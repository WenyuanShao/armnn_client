#!/bin/sh

sudo killall armnn_*


python start_client.py \
		-s 10.10.1.7 \
		-p 8080 \
		--nb_cores $1 \
		--nb_request 10 \
		--nb_client $2 \
		--first_client_port 11211 \
