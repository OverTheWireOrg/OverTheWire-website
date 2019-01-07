#!/bin/bash

set -e
shopt -s nullglob

basedir=$(dirname $(readlink -f $0))
tmpfile=$(mktemp)

cd $basedir
./patreon.py *.csv > $tmpfile
cat $tmpfile | tee ../_includes/patreonlist.md
rm -f $tmpfile
