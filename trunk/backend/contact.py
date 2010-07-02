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


class Contact(object):
    keys = ['id', 'name', 'forename', 'email', 'nickname', 'contactname', 'company', 'company_city', 'company_postal', 'company_street', 'company_housenumber', 'company_telephone', 'company_fax', 'telephone_private', 'telephone_car', 'fax_private', 'street', 'housenumber', 'city', 'postal', 'state', 'country', 'image', 'webpage', 'icq', 'skype', 'jabber', 'aol', 'msn']
    content = []    
    def __init__(self, content):

        if (content == None):
            self.content = {'id':-1, 'name':'', 'forename':'', 'email':'', 'nickname':'', 'contactname':'',\
                             'company':'', 'company_city':'', 'company_postal':'', 'company_street':'', 'company_housenumber':'',\
                             'company_telephone':'', 'company_fax':'', 'telephone_private':'', 'telephone_car':'', 'fax_private':'',\
                             'street':'', 'housenumber':'', 'city':'', 'postal':'', 'state':'', 'country':'', 'image':'', 'webpage':'', 'icq':'', 'skype':'', 'jabber':'', 'aol':'', 'msn':''} 
            content = self.content
        else:
            self.content = dict(content)
#        self.id = content[0]
#        self.name = content[1]
#        self.forename = content[2]
#        self.email = content[3]
#        self.nickname = content[4]
#        self.contactname = content[5]
#        self.company = content[6]
#        self.busCity = content[7]
#        self.busPostal = content[8]
#        self.busStreet = content[9]
#        self.busStreetNumber = content[10]
#        self.busTelephone = content[11]
#        self.busFax = content[12]
#        self.telephone = content[13]
#        self.telephone_car = content[14]
#        self.fax = content[15]
#        self.street = content[16]
#        self.streetNumber = content[17]
#        self.city = content[18]
#        self.postal = content[19]
#        self.state = content[20]
#        self.country = content[21]
#        self.imagePath = content[22]
#        self.website = content[23]
#        self.icq = content[24]
#        self.skype = content[25]
#        self.jabber = content[26]
#        self.aim = content[27]
#        self.msn = content[28]


    def save(self):
        return 0
    
    def get_content(self):
#        content = []
#        content[0] = self.id
#        content[1] = self.name
#        content[2] = self.forename
#        content[3] = self.email
#        content[4] = self.nickname
#        content[5] = self.contactname
#        content[6] = self.company
#        content[7] = self.busCity
#        content[8] = self.busPostal
#        content[9] = self.busStreet
#        content[10] = self.busStreetNumber
#        content[11] = self.busTelephone
#        content[12] = self.busFax
#        content[13] = self.telephone
#        content[14] = self.telephone_car
#        content[15] = self.fax
#        content[16] = self.street
#        content[17] = self.streetNumber
#        content[18] = self.city
#        content[19] = self.postal
#        content[20] = self.state
#        content[21] = self.country
#        content[22] = self.imagePath
#        content[23] = self.website
#        content[24] = self.icq
#        content[25] = self.skype
#        content[26] = self.jabber
#        content[27] = self.aim
#        content[28] = self.msn
        return self.content        
    
    
    def __setattr__(self,name,value):
        if(name in object.__getattribute__(self,"keys")):
            self.content[name]=value
        else:
            object.__setattr__(self,name,value)
    
    def __getattribute__(self,name):
        if(name in object.__getattribute__(self,"keys")):
            return self.content[name]
        else:
            return object.__getattribute__(self,name)
        
    def __getitem__(self, name):
        #print name
        return self.content[name]

class ContactManager:


    def get_list(self):
        return 0
    
    def close(self):
        return None
