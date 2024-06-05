#!/bin/sh

ifconfig | grep -Po 'ether \K[^ ]*'