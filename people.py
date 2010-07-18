#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
# This file is part of peopleedit.
#
# Copyright(c) Stefan Lüdtke
#
# This file may be licensed under the terms of of the
# GNU General Public License Version 3 (the "GPL").
#
# Software distributed under the License is distributed
# on an "AS IS" basis, WITHOUT WARRANTY OF ANY KIND, either
# express or implied. See the GPL for the specific language
# governing rights and limitations.
#
# You should have received a copy of the GPL along with this
# program. If not, go to http://www.gnu.org/licenses/gpl.html
# or write to the Free Software Foundation, Inc.,
# 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
#

import sys

#from gda import *
import glob

import gobject
import locale
import gettext
import os
import subprocess

try:
    import pygtk
    pygtk.require("2.0")
except:
    pass
import gtk
import gtk.glade
import gtk.gdk


from backend.sqlite import *
from backend.vcard import *
from backend.config import *

# import gui stuff
from gui.options import OptionsDialog
APP_DIR = os.path.dirname(__file__) or "."
APP_NAME = 'people'
LOCALE_DIR = APP_DIR+'/locale'
try:
    locale.setlocale(locale.LC_ALL, '')
except:
    locale.setlocale(locale.LC_ALL, 'en_US.UTF-8')
gettext.bindtextdomain(APP_NAME, LOCALE_DIR)
gettext.textdomain(APP_NAME)
gettext.install(APP_NAME, LOCALE_DIR, unicode=1)
_ = gettext.gettext

for module in (gettext, gtk.glade):
    module.bindtextdomain(APP_NAME, LOCALE_DIR)
    module.textdomain(APP_NAME)
global use_magi
try:
    import libs.magikit
    libs.magikit.inito()
    use_magi = 1
except:
    import gconf
    use_magi = 0




class PeopleEdit:
    column_names = [_('Name'), _('forname'), _('email'), _('nickname')]
    selected = None
    version = "2.0 Beta"
    config = None
    path = os.path.dirname(__file__) or "."
    def __init__(self):
        global home
        """
        
        """
        # init config
        home = os.getenv('USERPROFILE') or os.getenv('HOME')
        self.config = myconfig

        # init db manager
        if(self.config.backend.lower() =="sqlite"):
            self.manager = SQLiteManager()
        elif(self.config.backend.lower() =="vcard"):
            self.manager = VCardManager()


        self.contacts = []
        cell_data_funcs = (self.view_name, self.view_vorname, self.view_email, self.view_spitzname)
        #init user interface

        self.gladefile = "gui.glade"
        self.builder = gtk.Builder()
        self.builder.add_from_file(self.path+"/people.glade")
        dic = {"on_mainWindow_destroy": self.quit_window, "on_aboutButton_clicked": self.about_button_clicked, \
        "on_newButton_clicked": self.new_button_clicked, \
        "on_treeview_cursor_changed":self.treeviewSelected, \
        "on_saveButton_clicked":self.saveButton_clicked, \
        "on_optionsButton_clicked":self.option_button_clicked, \
        "on_nameEntry_changed":self.nameentry_changed, \
        "on_forenameEntry_changed":self.forenameentry_changed, \
        "on_deleteButton_clicked":self.deletebutton_clicked, \
        "on_nicknameEntry_changed":self.nicknameentry_changed, \
        "on_contactEntry_changed":self.contactentry_changed, \
        "on_postalEntry_changed":self.postalentry_changed, \
        "on_cityEntry_changed":self.cityentry_changed, \
        "on_streetEntry_changed":self.streetentry_changed, \
        "on_streetNumberEntry_changed":self.streetnumberentry_changed, \
        "on_countryEntry_changed":self.countryentry_changed, \
        "on_busPhoneEntry_changed":self.busphoneentry_changed, \
        "on_busFaxEntry_changed":self.busfaxentry_changed, \
        "on_busCityEntry_changed":self.buscityentry_changed, \
        "on_busPostalEntry_changed":self.buspostalentry_changed, \
        "on_busStreetEntry_changed":self.busstreetentry_changed, \
        "on_busStreetNumberEntry_changed":self.busstreetnumberentry_changed, \
        "on_companyEntry_changed":self.companyentry_changed, \
        "on_filechooserButton_file_activated":self.filechooser_confirmed, \
        "on_showImageButton_clicked":self.show_image_button_clicked, \
        "on_websiteEntry_changed":self.websiteentry_changed, \
        "on_emailEntry_changed":self.emailentry_changed, \
        "on_send_mail_button_clicked":self.sendmail_button_clicked, \
        "on_visitPageButton_clicked":self.visitpage_button_clicked, \
        "on_msnEntry_changed":self.msnentry_changed, \
        "on_aimEntry_changed":self.aimentry_changed, \
        "on_jabberEntry_changed":self.jabberentry_changed, \
        "on_icqEntry_changed":self.icqentry_changed,\
        "on_vcardMenuExport_activate":self.vcard_menu_export,\
        "on_vcardMenuImport_activate":self.vcard_menu_import,\
        "on_searchEntry_changed":self.search}
        self.builder.connect_signals(dic)
        self.input = self.builder.get_object("chat_input")
        self.content = self.builder.get_object("content")
        self.mainwindow = self.builder.get_object("mainWindow")
        if os.path.exists("/usr/share/pixmaps/peopleedit.png"):
            self.mainwindow.set_icon_from_file("/usr/share/pixmaps/peopleedit.png")
        else:
            self.mainwindow.set_icon_from_file("peopleedit.png")
        self.treeview = self.builder.get_object("treeview")
        #set size of the window
        self.mainwindow.set_default_size(443, 570)
        #create filter for the picture selection
        filter = gtk.FileFilter()
        filter.set_name("Images")
        filter.add_pattern("*.png")
        filter.add_pattern("*.jpeg")
        filter.add_pattern("*.jpg")
        self.builder.get_object("filechooserButton").add_filter(filter)
        self.tvcolumn = [None] * len(self.column_names)
        #self.treeview.append_column(self.tvcolumn[0])
        for n in range(0, len(self.column_names)):
            cell = gtk.CellRendererText()
            self.tvcolumn[n] = gtk.TreeViewColumn(self.column_names[n], cell)
            if n == 1:
                cell.set_property('xalign', 1.0)
            self.tvcolumn[n].set_cell_data_func(cell, cell_data_funcs[n])
            self.treeview.append_column(self.tvcolumn[n])
        self.listmodel = gtk.ListStore(object)
        # add contacts to the listmodel
        self.listmodel = self.manager.get_list()
        
        self.listfilter = self.listmodel.filter_new()
        
        #self.treeview.connect('row-activated', self.open_file)
        
        self.search_data = []
        self.listfilter.set_visible_func(self.visible_cb,self.search_data)
        self.treeview.set_model(self.listfilter)
        #self.treeview.set_model(self.listmodel)
        #self.loadFiles(os.getenv("HOME") + '/contacts')
        # select first entry
        selection = self.treeview.get_selection()
        if(self.treeview.get_model().get_iter_first() != None):
            selection.select_iter(self.treeview.get_model().get_iter_first())
            self.treeviewSelected(None)
        else:
            self.set_fields_editable()
        
        #tmp = vcard.VCardManager()
        
        # show everything
        self.treeview.show()
        self.mainwindow.show()
    
    def set_fields_editable(self,edit=False): 
        self.builder.get_object("nameEntry").set_editable(False)
        self.builder.get_object("nicknameEntry").set_editable(False)
        self.builder.get_object("forenameEntry").set_editable(False)
        self.builder.get_object("contactEntry").set_editable(False)
        self.builder.get_object("emailEntry").set_editable(False)
        self.builder.get_object("companyEntry").set_editable(False)
        self.builder.get_object("cityEntry").set_editable(False)  
        self.builder.get_object("busCityEntry").set_editable(False)
        self.builder.get_object("busPostalEntry").set_editable(False)
        self.builder.get_object("busStreetEntry").set_editable(False)
        self.builder.get_object("busStreetNumberEntry").set_editable(False)
        self.builder.get_object("busPhoneEntry").set_editable(False)
        self.builder.get_object("busFaxEntry").set_editable(False)
        self.builder.get_object("websiteEntry").set_editable(False)
        self.builder.get_object("countryEntry").set_editable(False)
        self.builder.get_object("streetEntry").set_editable(False)
        self.builder.get_object("streetNumberEntry").set_editable(False)
        self.builder.get_object("postalEntry").set_editable(False)
        self.builder.get_object("icqEntry").set_editable(False)
        self.builder.get_object("aimEntry").set_editable(False)
        self.builder.get_object("jabberEntry").set_editable(False)
        self.builder.get_object("msnEntry").set_editable(False)
                
    def search(self,widget):
        del self.search_data[:]
        self.search_data.append(widget.get_text())
        self.listfilter.refilter()
    
    def visible_cb(self, model, iter, data):
        if len(data)>0 and model.get_value(iter, 0)!= None:
            cont= model.get_value(iter, 0).content
            for tmp in cont:
                if str(cont[tmp]).find(data[0])>-1:
                    return True
            return False
        else:
            #print model.get_value(iter, 0) in data
            return True
    
    def close(self):
        self.manager.close()
        self.config.close()

    def change(self,widget,name):
        treeselection = self.treeview.get_selection()
        (filter, iter) = treeselection.get_selected()
        valid_iter=filter.convert_iter_to_child_iter(iter)
        if (iter == None):
            return None
        model = filter.get_model()
        tmp2 = model.get_value(valid_iter, 0)
        tmp2.__setattr__(name,widget.get_text())
        model.set_value(valid_iter, 0, tmp2)
               
    def nameentry_changed(self, widget):
        self.change(widget, "name")

    def forenameentry_changed(self, widget):
        self.change(widget, "forename")

        
    def nicknameentry_changed(self, widget):
        self.change(widget, "nickname")
        
    def contactentry_changed(self, widget):
        self.change(widget, "contactname")
    
    def postalentry_changed(self, widget):
        treeselection = self.treeview.get_selection()
        (filter, iter) = treeselection.get_selected()
        valid_iter=filter.convert_iter_to_child_iter(iter)
        if (iter == None):
            return None        
        model = filter.get_model()
        tmp2 = model.get_value(valid_iter, 0)
        try:
            if (len(widget.get_text()) > 0):
                tmp2.postal = int(widget.get_text())
        except:
            md = gtk.MessageDialog(self.mainwindow,
            gtk.DIALOG_DESTROY_WITH_PARENT, gtk.MESSAGE_ERROR,
            gtk.BUTTONS_CLOSE, "You can not write characters here.")
            md.run()
            md.destroy()
        model.set_value(valid_iter, 0, tmp2)
    
    def cityentry_changed(self, widget):
        self.change(widget, "city")

    def streetentry_changed(self, widget):
        self.change(widget, "street")
        
    def streetnumberentry_changed(self, widget):
        self.change(widget, "streetNumber")

    def countryentry_changed(self, widget):
        self.change(widget, "country")

    
    def busphoneentry_changed(self, widget):
        self.change(widget, "company_telephone")

    def busfaxentry_changed(self, widget):
        self.change(widget, "company_fax")
            
    def buscityentry_changed(self, widget):
        self.change(widget, "company_city")
    
    def buspostalentry_changed(self, widget):
        self.change(widget, "company_postal")
    
    def busstreetentry_changed(self, widget):
        self.change(widget, "company_street")
    
    def busstreetnumberentry_changed(self, widget):
        self.change(widget, "company_housenumber")
        
    def companyentry_changed(self, widget):
        self.change(widget, "company") 
    
    def filechooser_confirmed(self, widget):
        treeselection = self.treeview.get_selection()
        (filter, iter) = treeselection.get_selected()
        valid_iter=filter.convert_iter_to_child_iter(iter)
        if (iter == None):
            return None
        model = filter.get_model()
        tmp2 = model.get_value(valid_iter, 0)
        if (widget.get_filename() <> None and os.path.isfile(widget.get_filename())):
            tmp2.imagePath = widget.get_filename()
            model.set_value(valid_iter, 0, tmp2)
            self.builder.get_object("image").set_from_pixbuf(gtk.gdk.pixbuf_new_from_file(tmp2.imagePath).scale_simple(100, 100, gtk.gdk.INTERP_BILINEAR))
    
    def websiteentry_changed(self, widget):
        self.change(widget, "webpage")
    
    def emailentry_changed(self, widget):
        self.change(widget, "email")
    
    def msnentry_changed(self, widget):
        self.change(widget, "msn")
 
    def icqentry_changed(self, widget):
        self.change(widget, "icq")  
        
    def jabberentry_changed(self, widget):
        self.change(widget, "jabber")

    def aimentry_changed(self, widget):
        self.change(widget, "aim")
            
    '''
        views of the Table
    '''
    def view_name(self, column, cell, model, iter):
        contact = model.get_value(iter, 0)
        cell.set_property('text', contact.name)
    def view_vorname(self, column, cell, model, iter):
        contact = model.get_value(iter, 0)
        cell.set_property('text', contact.forename)
    def view_email(self, column, cell, model, iter):
        contact = model.get_value(iter, 0)
        cell.set_property('text', contact.email)
    def view_spitzname(self, column, cell, model, iter):
        contact = model.get_value(iter, 0)
        cell.set_property('text', contact.nickname)

    def treeviewSelected(self, widget):
        treeselection = self.treeview.get_selection()
        
        self.selected = treeselection
        
        (model, iter) = treeselection.get_selected()
        if (iter == None):
            return None
        tmp = model.get_value(iter, 0)

        if tmp.name != None:
            self.builder.get_object("nameEntry").set_text(tmp.name)
        else:
            self.builder.get_object("nameEntry").set_text("")
        if tmp.nickname != None:
            self.builder.get_object("nicknameEntry").set_text(tmp.nickname)
        else:
            self.builder.get_object("nicknameEntry").set_text("")
        if tmp.forename != None:
            self.builder.get_object("forenameEntry").set_text(tmp.forename)
        else:
            self.builder.get_object("forenameEntry").set_text("")
        if tmp.contactname != None:
            self.builder.get_object("contactEntry").set_text(tmp.contactname)
        else:
            self.builder.get_object("contactEntry").set_text("")
        if tmp.email != None:
            self.builder.get_object("emailEntry").set_text(tmp.email)
        else:
            self.builder.get_object("emailEntry").set_text("")
        if tmp.company != None:
            self.builder.get_object("companyEntry").set_text(tmp.company)
        else:
            self.builder.get_object("companyEntry").set_text("")
        if tmp.city != None:
            self.builder.get_object("cityEntry").set_text(tmp.city)
        else:
            self.builder.get_object("cityEntry").set_text("")            
        if tmp.company_city != None:
            self.builder.get_object("busCityEntry").set_text(tmp.company_city)
        else:
            self.builder.get_object("busCityEntry").set_text("")
        if tmp.company_postal != None:
            self.builder.get_object("busPostalEntry").set_text(str(tmp.company_postal))
        else:
            self.builder.get_object("busPostalEntry").set_text("")
        if tmp.company_street != None:
            self.builder.get_object("busStreetEntry").set_text(tmp.company_street)
        else:
            self.builder.get_object("busStreetEntry").set_text("")
        if tmp.company_housenumber != None:
            self.builder.get_object("busStreetNumberEntry").set_text(tmp.company_housenumber)
        else:
            self.builder.get_object("busStreetNumberEntry").set_text("")
        if tmp.company_telephone != None:
            self.builder.get_object("busPhoneEntry").set_text(tmp.company_telephone)
        else:
            self.builder.get_object("busPhoneEntry").set_text("")            
        if tmp.company_fax != None:
            self.builder.get_object("busFaxEntry").set_text(tmp.company_fax)
        else:
            self.builder.get_object("busFaxEntry").set_text("") 
        if tmp.webpage != None:
            self.builder.get_object("websiteEntry").set_text(tmp.webpage)
        else:
            self.builder.get_object("websiteEntry").set_text("")
        if tmp.country != None:
            self.builder.get_object("countryEntry").set_text(tmp.country)
        else:
            self.builder.get_object("countryEntry").set_text("")            
        if tmp.street != None:
            self.builder.get_object("streetEntry").set_text(tmp.street)
        else:
            self.builder.get_object("streetEntry").set_text("")
        if tmp.housenumber != None:
            self.builder.get_object("streetNumberEntry").set_text(tmp.housenumber)
        else:
            self.builder.get_object("streetNumberEntry").set_text("")
        if tmp.postal != None:
            self.builder.get_object("postalEntry").set_text(str(tmp.postal))
        else:
            self.builder.get_object("postalEntry").set_text("")
        if tmp.icq != None:
            self.builder.get_object("icqEntry").set_text(tmp.icq)
        else:
            self.builder.get_object("icqEntry").set_text("")
        if tmp.aol != None:
            self.builder.get_object("aimEntry").set_text(tmp.aol)
        else:
            self.builder.get_object("aimEntry").set_text("")
        if tmp.jabber != None:
            self.builder.get_object("jabberEntry").set_text(tmp.jabber)
        else:
            self.builder.get_object("jabberEntry").set_text("")
        if tmp.msn != None:
            self.builder.get_object("msnEntry").set_text(tmp.msn)
        else:
            self.builder.get_object("msnEntry").set_text("")
        #load image if exists
        if (tmp.image != None and os.path.exists(tmp.image)):
            self.builder.get_object("image").set_from_pixbuf(gtk.gdk.pixbuf_new_from_file(tmp.image).scale_simple(100, 100, gtk.gdk.INTERP_BILINEAR))

            self.builder.get_object("filechooserButton").set_filename(tmp.image)
        else:
            self.builder.get_object("image").clear()
            self.builder.get_object("filechooserButton").set_filename("")
            
    def new_button_clicked(self, widget):
        iter = self.listmodel.append([self.manager.new_contact()])
        treeselection = self.treeview.get_selection()
        (filter, iter2) = treeselection.get_selected()
        valid_iter=filter.convert_child_iter_to_iter(iter)
        treeselection.select_iter(valid_iter)    
        self.treeviewSelected(None)
        # set all entries editable
        self.builder.get_object("nameEntry").set_editable(True)
        self.builder.get_object("nicknameEntry").set_editable(True)
        self.builder.get_object("forenameEntry").set_editable(True)
        self.builder.get_object("contactEntry").set_editable(True)
        self.builder.get_object("emailEntry").set_editable(True)
        self.builder.get_object("companyEntry").set_editable(True)
        self.builder.get_object("cityEntry").set_editable(True)  
        self.builder.get_object("busCityEntry").set_editable(True)
        self.builder.get_object("busPostalEntry").set_editable(True)
        self.builder.get_object("busStreetEntry").set_editable(True)
        self.builder.get_object("busStreetNumberEntry").set_editable(True)
        self.builder.get_object("busPhoneEntry").set_editable(True)
        self.builder.get_object("busFaxEntry").set_editable(True)
        self.builder.get_object("websiteEntry").set_editable(True)
        self.builder.get_object("countryEntry").set_editable(True)
        self.builder.get_object("streetEntry").set_editable(True)
        self.builder.get_object("streetNumberEntry").set_editable(True)
        self.builder.get_object("postalEntry").set_editable(True)
        self.builder.get_object("icqEntry").set_editable(True)
        self.builder.get_object("aimEntry").set_editable(True)
        self.builder.get_object("jabberEntry").set_editable(True)
        self.builder.get_object("msnEntry").set_editable(True) 
        """
            
        """
    def about_button_clicked(self, widget):
        about = gtk.AboutDialog()
        about.set_program_name("peopleEdit")
        about.set_version(self.version)
        about.set_copyright("(c) Stefan Luedtke")
        about.set_comments("peopleEdit is a simple contact management tool")
        about.set_website("http://peopleedit.silver-boards.com")
        if os.path.exists("/usr/share/pixmaps/peopleedit.png"):        
                about.set_logo(gtk.gdk.pixbuf_new_from_file("/usr/share/pixmaps/peopleedit.png"))
        else:
            about.set_logo(gtk.gdk.pixbuf_new_from_file("peopleedit.png"))
        about.run()
        about.destroy()

    def saveButton_clicked(self, widget):
        for line in self.listmodel:
            for cell in line:
                cell.save()

    def deletebutton_clicked(self, widget):
        treeselection = self.treeview.get_selection()
        (filter, iter) = treeselection.get_selected()
        valid_iter=filter.convert_iter_to_child_iter(iter)
        if (iter == None):
            return None
        model = filter.get_model()
        tmp2 = model.get_value(valid_iter, 0)
        tmp2.delete()
        self.listmodel.remove(valid_iter)
        if self.listmodel.__len__() == 0:
            self.set_fields_editable()
        # select first entry
        selection = self.treeview.get_selection()
        if(self.treeview.get_model().get_iter_first() != None):
            selection.select_iter(self.treeview.get_model().get_iter_first())
            self.treeviewSelected(None)        

    def quit_window(self, widget):
        gtk.main_quit()
        
    def option_button_clicked(self, widget):
        #md = gtk.MessageDialog(self.mainwindow,
        #gtk.DIALOG_DESTROY_WITH_PARENT, gtk.MESSAGE_INFO,
        #gtk.BUTTONS_CLOSE, "This dialog is not available yet.")
        md = OptionsDialog()
        md.run()
    
    def show_image_button_clicked(self, widget):
        treeselection = self.treeview.get_selection()
        (model, iter) = treeselection.get_selected()
        if (iter == None):
            return None
        tmp2 = model.get_value(iter, 0)
        if (tmp2.image <> None and os.path.isfile(tmp2.image)):
            #p=subprocess.Popen("/usr/bin/eog "+tmp2.imagePath)
            pid = subprocess.Popen(["/usr/bin/eog", tmp2.image]).pid
            
    def sendmail_button_clicked(self, widget):
        client = gconf.client_get_default()
        mail = self.config["email-unix_"+self.config["email"]]
        
        treeselection = self.treeview.get_selection()
        (model, iter) = treeselection.get_selected()
        if (iter == None):
            return None
        tmp = model.get_value(iter, 0)
        mail=mail.replace('%s', tmp.email)
        mail = mail.split(" ")
        if(len(tmp.email) > 0):
            pid = subprocess.Popen(mail).pid
    
    def visitpage_button_clicked(self, widget):
        client = gconf.client_get_default()
        if (not use_magi):
            browser = client.get_string("/desktop/gnome/applications/browser/exec")
        else:
            browser = libs.magikit.browser
            
        treeselection = self.treeview.get_selection()
        (model, iter) = treeselection.get_selected()
        if (iter == None):
            return None
        tmp = model.get_value(iter, 0)
        if (len(tmp.webpage) > 0):
            pid = subprocess.Popen([browser, tmp.webpage]).pid
            
    def vcard_menu_export(self,widget):
        treeselection = self.treeview.get_selection()
        (model, iter) = treeselection.get_selected()
        if (iter == None):
            return None
        tmp = model.get_value(iter,0)
        
        dialog=gtk.FileChooserDialog(title=None,action=gtk.FILE_CHOOSER_ACTION_SAVE,
                                  buttons=(gtk.STOCK_CANCEL,gtk.RESPONSE_CANCEL,gtk.STOCK_SAVE,gtk.RESPONSE_OK))
        filter = gtk.FileFilter()
        filter.set_name("Contacts")
        filter.add_mime_type("text/vcf")
        filter.add_pattern("*.vcf")
        dialog.add_filter(filter)        
        response = dialog.run()
        if response == gtk.RESPONSE_OK:
            print dialog.get_filename(), 'selected'
            #print tmp.content
            card = VCard(content=tmp.content)
            card.path=dialog.get_filename()
            card.save()
            dialog.destroy()
        elif response == gtk.RESPONSE_CANCEL:
            dialog.destroy()
        
    def vcard_menu_import(self,widget):
        dialog=gtk.FileChooserDialog(title=None,action=gtk.FILE_CHOOSER_ACTION_OPEN,
                                  buttons=(gtk.STOCK_CANCEL,gtk.RESPONSE_CANCEL,gtk.STOCK_OPEN,gtk.RESPONSE_OK))
        filter = gtk.FileFilter()
        filter.set_name("Contacts")
        filter.add_mime_type("text/vcf")
        filter.add_pattern("*.vcf")
        dialog.add_filter(filter)
        response = dialog.run()
        if response == gtk.RESPONSE_OK:
            card = VCard(path=dialog.get_filename())
            iter = self.listmodel.append([self.manager.new_contact(card.get_content())])
            selection = self.treeview.get_selection()
            selection.select_iter(iter)    
            self.treeviewSelected(None)                 
            dialog.destroy()
        elif response == gtk.RESPONSE_CANCEL:
            dialog.destroy() 
    
def version():
    print "version: "+PeopleEdit.version
    print "author: Stefan Lüdtke"
    print "builddate: 05/12/2010"                     

def run(argv):
    import sys
    if len(argv)>1 and argv[1] =="--version":
        version()
    else:
        print __file__
        edit = PeopleEdit()
        gtk.main()
        edit.close()
    
if __name__ == "__main__":
    run(sys.argv)
