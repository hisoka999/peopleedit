class VCardValue:
    def __init__(self, name, parameter, content):
        self.name = name
        self.parameter = parameter
        self.content = content
        
def parseLine(line):
    erg = line.split(':')
    content = erg[1]
    tmp = erg[0].split(';')
    name = erg[0]
    parameter = erg[1:]
    return VCardValue(name, parameter, content)
class VCard:
    def __init__(self, filename=""):
        if filename == "":
            self.name = ""
            self.icq = ""
            self.street = 0
            self.city = ""
        else:
            handle = open(filename)
            #while (line=handle.readline())==true:
            #    value=parseLine(line)
                

