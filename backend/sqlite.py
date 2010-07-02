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


__author__ = "stefan"
__date__ = "$17.09.2009 17:18:49$"

import sqlite3 as sqlite

from backend import contact
import os
import sys

try:
    import pygtk
    pygtk.require("2.0")
except:
    pass
try:
    import gtk
except:
    sys.exit(1)


class SQLiteContact(contact.Contact):
    def __init__(self, cursor, content):
        print content
        contact.Contact.__init__(self, content)
        self.cursor = cursor

    def save(self):
        if(self.id == -1):
            self.insert()
        else:
            self.update()
            
    def update(self):
        #print "update "+self.name
        self.cursor.execute('UPDATE contacts SET name=?,forename=?,email=?,contactname=?,nickname=?,company=?,company_city=?,company_postal=?,company_street=?,company_housenumber=?,\
                            company_telephone=?,company_fax=?,telephone_private=?,telephone_car=?,fax_private=?,street=?,housenumber=?,city=?,postal=?,state=?,country=?,image=?,webpage=?,icq=?,skype=?,jabber=?,aol=?,msn=? WHERE id=?', \
                            (self.name, self.forename, self.email, self.contactname, self.nickname, self.company, self.company_city, self.company_postal, self.company_street, self.company_housenumber, self.company_telephone,
                             self.company_fax, self.telephone_private, self.telephone_car, self.fax_private, self.street, self.housenumber, self.city, self.postal, self.state, self.country, self.image, self.webpage, self.icq, self.skype, self.jabber, self.aol, self.msn, self.id))

    def insert(self):
        self.cursor.execute('INSERT INTO contacts(id,name,forename,email,contactname,nickname,company,company_city,company_postal,company_street,company_housenumber,\
                            company_telephone,company_fax,telephone_private,telephone_car,fax_private,street,housenumber,city,postal,state,country,image,webpage,icq,skype,jabber,aol,msn) VALUES(NULL,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)', \
                            (self.name, self.forename, self.email, self.contactname, self.nickname, self.company, self.company_city, self.company_postal, self.company_street, self.company_housenumber, self.company_telephone,
                             self.company_fax, self.telephone_private, self.telephone_car, self.fax_private, self.street, self.housenumber, self.city, self.postal, self.state, self.country, self.image, self.webpage, self.icq, self.skype, self.jabber, self.aol, self.msn))

    def delete(self):
        if (self.id >= 0):
            self.cursor.execute('DELETE FROM contacts WHERE id=?', (self.id,))


class SQLiteManager(contact.ContactManager):
    def __init__(self):
        home = os.getenv('USERPROFILE') or os.getenv('HOME')
        base_path = home + '/.config/peopleedit'
        path = base_path + '/data.db'
        if (os.path.exists(path) == False):
            if (os.path.exists(base_path) == False):
                os.mkdir(base_path)
            self.connection = sqlite.connect(path)
            self.cursor = self.connection.cursor()
            self.cursor.execute('CREATE TABLE contacts \
                                (id INTEGER PRIMARY KEY , name VARCHAR , forename VARCHAR , email VARCHAR , nickname VARCHAR , contactname VARCHAR , company VARCHAR ,\
                                company_city VARCHAR , company_postal INTEGER , company_street VARCHAR , company_housenumber VARCHAR , company_telephone VARCHAR , company_fax VARCHAR , \
                                telephone_private VARCHAR , telephone_car VARCHAR , fax_private VARCHAR , street VARCHAR , housenumber VARCHAR , city VARCHAR , postal INTEGER , \
                                state VARCHAR , country VARCHAR , image VARCHAR , webpage VARCHAR , icq VARCHAR , skype VARCHAR , jabber VARCHAR , aol VARCHAR , msn VARCHAR);')
        else:
            self.connection = sqlite.connect(path)
            self.connection.row_factory = sqlite.Row
            self.cursor = self.connection.cursor()            

        self.cursor.execute('SELECT * FROM contacts')

    def get_list(self):
        listmodel = gtk.ListStore(object)
        for row in self.cursor:
            listmodel.append([SQLiteContact(self.cursor, row)])

        return listmodel

    def new_contact(self,content=None):
        return SQLiteContact(self.cursor,content)
    
    def close(self):
        self.connection.commit()
        self.cursor.close()
        self.connection.close()
