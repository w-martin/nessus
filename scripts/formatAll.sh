#!/bin/sh
find ../ -regex '.*\.\(cpp\|hpp\)$' -exec ./format.sh {} \;

