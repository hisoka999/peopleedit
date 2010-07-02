'''
Created on 15.11.2009

@author: stefan
'''
import ConfigParser
import os

global myconfig
home = os.getenv('USERPROFILE') or os.getenv('HOME')
class Config(dict):
    
    backend = ""
    _config = None
    
    def __init__(self,path):
        self.path = path
        if (os.path.exists(path) == False):
            f = open(path,"w")
            f.close()
            
        self._config=ConfigParser.RawConfigParser()
        self._config.readfp(open(path,"r"))
        if (len(self._config.sections()) == 0):
            self.init_config()
        self.backend = self._config.get("global", "backend")
        
    def close(self):
        import people
        self._config.set("global", "version", people.PeopleEdit.version)
        self._config.write(open(self.path,"w"))
        
    def init_config(self):
        import people
        self._config.add_section("global")
        self._config.set("global", "backend", "sqlite")
        self._config.set("global", "version", people.PeopleEdit.version)
        self._config.set("global", "email","Standard")
        self._config.set("global", "vcard", home+"/people/")
        self._config.add_section("email-unix")
        self._config.set("email-unix", "Standard", "xdg-open mailto:%")
        self._config.set("email-unix", "Thunderbird", "/usr/bin/env thunderbird -compose to=%s")
        
        
    
    def __setitem__(self,name,value):
        arr=name.split('_')
        if (len(arr)==1):
            self._config.set("global", name, value)
        else:
            self._config.set(arr[0], arr[1], value)
            
    def __getitem__(self,name):
        arr=name.split('_')
        if (len(arr)==1 and self._config.has_option("global", name)):
            return self._config.get("global", name.lower())
        else:
            return self._config.get(arr[0].lower(),arr[1].lower())
    
    def get_options(self,section):
        return self._config.options(section)
    

myconfig = Config(home+"/.config/peopleedit/people.conf")
