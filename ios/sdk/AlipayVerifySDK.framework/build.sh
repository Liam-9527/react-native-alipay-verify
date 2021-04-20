#!/bin/sh
rm -rf Products;
mkdir Products;
[ -f ~/.aptkit/bin/build.sh ] && { ~/.aptkit/bin/build.sh; };
cp -av Sources/*/*.framework Products/
