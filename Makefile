NAME = peopleedit

DATADIR = $(ROOT)/share
LOCALE_DIR = $(ROOT)/share/locale
BIN_DIR = $(ROOT)/bin
IMG_DIR = $(ROOT)/share/pixmaps

all:    peopleedit
    
peopleedit: 
	python -m compileall .

install: 
	mkdir -p $(DATADIR)/$(NAME)
	mkdir -p $(LOCALE_DIR)
	mkdir -p $(BIN_DIR)
	mkdir -p $(IMG_DIR)
	cp -R *.py *.pyc *.glade gui/ backend/ libs/ $(DATADIR)/$(NAME)
	cp -R locale/* $(LOCALE_DIR)
	ln -s /usr/share/$(NAME)/people.py $(BIN_DIR)/peopleedit
	install -D -m 0644 peopleedit.desktop $(DATADIR)/applications/peopleedit.desktop
	install -D -m 0644 peopleedit.png $(DATADIR)/pixmaps/peopleedit.png	
	chmod +x $(DATADIR)/$(NAME)/people.py

clean:
	find . -iname '*.pyc' -exec rm {} \;

uninstall:
	rm -R $(DATADIR)
	rm $(BIN_DIR)peopleedit
	rm $(IMG_DIR)peopleedit.png
	rm $(DATADIR)/applications/peopleedit.desktop
