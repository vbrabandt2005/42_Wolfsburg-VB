#!/bin/bash

ifconfig | grep -Po 'ether \K[^ ]*'