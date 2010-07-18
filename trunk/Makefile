NAME = peopleedit
#BUILDDIR = /tmp/$(NAME)/
DATADIR = /usr/share
LOCALE_DIR = /usr/share/locale
BIN_DIR = /usr/bin
IMG_DIR = /usr/share/pixmaps

all:    peopleedit
    
peopleedit: 
	python -m compileall .

install: 
	mkdir $(DATADIR)/$(NAME)
	cp -R *.py *.pyc *.glade gui/ backend/ libs/ $(DATADIR)/$(NAME)
	cp -R locale/* $(LOCALE_DIR)
	ln -s $(DATADIR)/$(NAME)/people.py $(BIN_DIR)/peopleedit
	install -D -m 0644 peopleedit.desktop $(DATADIR)/applications/peopleedit.desktop
	install -D -m 0644 peopleedit.png $(DATADIR)/pixmaps/peopleedit.png	
	chmod +x $(DATADIR)people.py

clean:
	find . -iname '*.pyc' -exec rm {} \;

uninstall:
	rm -R $(DATADIR)
	rm $(BIN_DIR)peopleedit
	rm $(IMG_DIR)peopleedit.png
	rm $(DATADIR)/applications/peopleedit.desktop
