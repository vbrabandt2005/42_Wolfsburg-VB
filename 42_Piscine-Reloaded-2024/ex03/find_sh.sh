#!/bin/bash

find . -type f -name "*.sh" -exec sh -c 'basename {} .sh' \;