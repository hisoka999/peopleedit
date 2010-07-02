#!/bin/sh
cp -R publish/ build/
mkdir -p build/usr/share/peopleedit/
cp -u *.py *.glade  build/usr/share/peopleedit/
cp -R backend/ locale/ gui/ libs/ build/usr/share/peopleedit/
#delete obsolete files
for i in `find build/usr/share/peopleedit/ -name "*.pyc"`
do
	rm $i
done
for i in `find build/ -name ".svn"`
do
	rm -R $i
done
dpkg -b build/ peopleedit-$1.deb
rm -R build/
