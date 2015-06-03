# $Id: Makefile,v 1.4 2004/12/02 18:35:21 archiecobbs Exp $

all:
	rm -rf website.tgz include share
	mkdir include include/jc share share/jc share/jc/doc share/jc/doc/api
	cp ../include/jc_defs.h include/jc
	( cd ../doc && make )
	cp ../doc/jc.html share/jc/doc/jc.html
	tar zxvf ../java/api.tgz -C share/jc/doc/api
	cp ../INSTALL share/jc/doc
	cp ../CHANGES share/jc/doc
	tar cfz website.tgz .

clean:
	rm -rf include share website.tgz

