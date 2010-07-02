'''
Created on 17.02.2010

@author: stefan
'''
import gtk
import os
from backend.config import * 

class OptionsDialog:
    '''
        this dialog is for changing all important options
    '''
    def __init__(self):
        self.gladefile = os.path.dirname(__file__)+"/options.glade"
        self.backend_ui=None
    
    
    def run(self):
        self.builder = gtk.Builder()
        self.builder.add_from_file(self.gladefile)
        self.window = self.builder.get_object("window")
        backend = self.builder.get_object("backend_box")
        #backend = gtk.combo_box_new_text()
        liststore = gtk.ListStore(str)
        cell = gtk.CellRendererText()
        backend.pack_start(cell)
        backend.add_attribute(cell, 'text', 0)
        liststore.append(['SQLite'])
        liststore.append(['vCard'])
        backend.set_model(liststore)
        backend.set_active(0)
        backend.connect('changed', self.changed_cb)
        
        
        #email
        email = self.builder.get_object("email_box")
        liststore = gtk.ListStore(str)
        cell = gtk.CellRendererText()
        email.pack_start(cell)
        email.add_attribute(cell,'text',0)
        for app in myconfig.get_options('email-unix'):
            liststore.append([app])
        email.set_model(liststore)
        email.set_active(0)
        
        response=self.window.run()                               
        # save options
        if(response == True):
            print "options saved"
            myconfig["backend"]=backend.get_active_text()
            myconfig["email"]=email.get_active_text()
        
        self.window.destroy()
    def changed_cb(self,combobox):
        model = combobox.get_model()
        index = combobox.get_active()
        if index > -1:
            self.set_backend(str(model[index][0]).lower())
            
        return
    def set_backend(self,backend):
        box=self.builder.get_object("backend_table")
        if (self.backend_ui!=None):
            box.remove(self.backend_ui)
        if(backend == "sqlite"):
            self.backend_ui = None
        elif(backend == "vcard"):
            self.backend_ui = self.builder.get_object("vcard")
            path_chooser= self.builder.get_object("path_chooser")
            try:
                path_chooser.set_current_folder(myconfig["vcard"])
            except:
                myconfig["vcard"]=os.getenv('USERPROFILE') or os.getenv('HOME')+"/people/"
                path_chooser.set_filename(myconfig["vcard"])
            #box.add(self.backend_ui)
            box.attach(self.backend_ui,0,2,1,2, xoptions=gtk.EXPAND|gtk.FILL, yoptions=gtk.FILL)
            self.backend_ui.show()
