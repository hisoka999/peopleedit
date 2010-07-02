'''
Created on 05.11.2009

@author: stefan
'''
from backend import contact

import gtk
import glob
import os
import vobject
from backend.config import * 

class VCard(contact.Contact):
    '''
    classdocs
    '''
    path = None
    email = ""
    street = ""
    city = ""
    webpage = ""
    postal = 0
    housenumber = 0
    country = ""
    
    def __init__(self,content=None,path=None):
        '''
        Constructor
        '''
        contact.Contact.__init__(self,content)
        if (path == None):
            return None
        self.path = path
        if (not os.path.exists(path)):
            return None
        file = open(path)
        v = vobject.readOne(file.read())
        
        
        
        #adr = v.adr
        try: 
            self.street=v.adr.value.street.split(' ')[0]
            self.housenumber = v.adr.value.street.split(' ')[1]
            self.city = v.adr.value.city
            self.postal = v.adr.value.code
            self.country = v.adr.value.country
            self.webpage = v.url.value
            self.email = v.email.value
        except:
            print "vcard is not complete"
        finally:
            self.forename = v.n.value.given
            self.name = v.n.value.family
                
        print self.webpage
    
    def delete(self):
        if(self.path!=None):
            os.remove(self.path)
    
    def save(self):
        if (self.path==None):
            self.path =VCardManager.path+self.name+"_"+self.forename+".vcf"
        v = vobject.vCard()
        v.add('n')
        v.n.value.family = self.name
        v.n.value.given = self.forename
        v.add('fn')
        v.fn.value =self.forename + " " +self.name
        v.add('email')
        v.email.value = self.email
        v.add('adr')
        v.adr.value.street = self.street+' '+self.housenumber
        v.adr.value.city = self.city
        v.adr.value.code = str(self.postal)
        v.adr.value.country = self.country
        v.add('url')
        v.url.value = self.webpage

        print self.path
        f = open(self.path,'w')
        f.write(v.serialize())
        f.close()
        #print v.prettyPrint()


class VCardManager(contact.ContactManager):
    path = None
    
    def __init__(self):
        try:
            self.path = myconfig["vcard"]
        except:
            myconfig["vcard"]=os.getenv('USERPROFILE') or os.getenv('HOME')+"/people/"
            self.path = myconfig["vcard"]
        self.get_list()
        
    
    def new_contact(self,content=None):
        return VCard(content=content)
    
    def get_list(self):
        listmodel = gtk.ListStore(object)
        for infile in glob.glob(os.path.join(self.path, '*.vcf')):
            print "File: " + infile
            listmodel.append([VCard(path=infile)])
        return listmodel
    
            
            