#!/usr/bin/python
# -*- coding: utf-8 -*-

# by Leszek Lesner 
# released under the terms of GPLv3 

###############################################################
# This app is a layer for magi2 apps and settings management  #
# Its purpose is to allow easily change app links aswell as   #
# setting links                                               #
###############################################################

import os, xml.dom, xml.dom.minidom, sys
browser, mail, rss, im, irc, nfs, skype =""
word, spreadsheet, presentation, imageeditor, calculator, calendar, pdf, notes =""
music, pictures, burn, rip, audioeditor, videoeditor, video =""
editor, ide =""
install, filemanager, archiver, search, konsole, package, screenshot=""
desktop, workspace, appearance, language, panel, wm, printer, power, display, mouse, keyboard, sound, user, time, update, sources, network, ndis, share=""

# Variables needed
home = os.getenv('USERPROFILE') or os.getenv('HOME')

# Create a default config
def initc() :
    # Create xml file
    implement = xml.dom.getDOMImplementation()
    doc = implement.createDocument(None, "magi-kit", None)

    # Child Elements 
    elem = doc.createElement("Internet")
    elem.setAttribute("Browser", "firefox")
    elem.setAttribute("Mail", "claws-mail")
    elem.setAttribute("Rss", "liferea")
    elem.setAttribute("IM", "pidgin")
    elem.setAttribute("IRC", "xchat")
    elem.setAttribute("Nfs", "gigolo")
    elem.setAttribute("Skype", "skype")

    # attach Child to document
    doc.documentElement.appendChild(elem)

    elem2 = doc.createElement("Office")
    elem2.setAttribute("Word", "abiword")
    elem2.setAttribute("Spreadsheet", "gnumeric")
    elem2.setAttribute("Presentation", "abiword")
    elem2.setAttribute("ImageEditor", "gimp")
    elem2.setAttribute("Calculator", "gcalctool")
    elem2.setAttribute("Calendar", "orage")
    elem2.setAttribute("PDF", "evince")
    elem2.setAttribute("Notes", "xpad")

    # attach Child to document
    doc.documentElement.appendChild(elem2)
 
    elem3 = doc.createElement("Multimedia")
    elem3.setAttribute("Music", "rhythmbox")
    elem3.setAttribute("Pictures", "gthumb")
    elem3.setAttribute("Burn", "brasero")
    elem3.setAttribute("Rip", "rhythmbox")
    elem3.setAttribute("AudioEditor", "audacity")
    elem3.setAttribute("VideoEditor", "avidemux")
    elem3.setAttribute("Video", "totem")

    # attach Child to document
    doc.documentElement.appendChild(elem3)

    elem4 = doc.createElement("Development")
    elem4.setAttribute("Editor", "mousepad")
    elem4.setAttribute("IDE", "geany")

    # attach Child to document
    doc.documentElement.appendChild(elem4)

    elem5 = doc.createElement("System")
    elem5.setAttribute("Install", "gksu ubiquity")
    elem5.setAttribute("FileManager", "thunar")
    elem5.setAttribute("Archiver", "file-roller")
    elem5.setAttribute("Search", "catfish")
    elem5.setAttribute("Konsole", "xfce4-terminal")
    elem5.setAttribute("Package", "gksu synaptic")
    elem5.setAttribute("Screenshot", "scrot")

    # attach Child to document
    doc.documentElement.appendChild(elem5)

    elem6 = doc.createElement("Settings")
    elem6.setAttribute("Desktop", "xfce-setting-show backdrop")
    elem6.setAttribute("Workspace", "sawfish-ui --group=workspace")
    elem6.setAttribute("Appearance", "xfce-setting-show ui")
    elem6.setAttribute("Language", "gksu gnome-language-selector")
    elem6.setAttribute("Panel", "xfce4-panel && xfce4-panel -c")
    elem6.setAttribute("WM", "sawfish-ui")
    elem6.setAttribute("Printer", "gksu system-config-printer")
    elem6.setAttribute("Power", "gnome-power-preferences")
    elem6.setAttribute("Display", "xfce-setting-show display")
    elem6.setAttribute("Mouse", "xfce-setting-show mouse")
    elem6.setAttribute("Keyboard", "xfce-setting-show keyboard")
    elem6.setAttribute("Sound", "alsamixergui")
    elem6.setAttribute("User", "gksu users-admin")
    elem6.setAttribute("Time", "gksu time-admin")
    elem6.setAttribute("Update", "/usr/sbin/update-manager")
    elem6.setAttribute("Sources", "gksu software-properties-gtk")
    elem6.setAttribute("Network", "gksu network-admin")
    elem6.setAttribute("Ndis", "gksu /usr/sbin/ndisgtk")
    elem6.setAttribute("Share", "gksu shares-admin")

    # attach Child to document
    doc.documentElement.appendChild(elem6)


    # write to file
    file = open(home + "/.magi-kit.xml", "w")
    doc.writexml(file, "\n", "  ")
    file.close()

def inito():
    global dom
    file = open(home + "/.magi-kit.xml", "r")
    dom = xml.dom.minidom.parse(file)
    file.close()
    dokument(dom)

def dokument(domina):

    Internetlist = domina.getElementsByTagName('Internet') 
    Internet = Internetlist[0]
    browser = Internet.attributes["Browser"]
    mail = Internet.attributes["Mail"]    
    rss = Internet.attributes["Rss"]
    im = Internet.attributes["IM"]
    irc = Internet.attributes["IRC"]
    nfs = Internet.attributes["Nfs"]
    skype = Internet.attributes["Skype"]

    Officelist = domina.getElementsByTagName('Office') 
    Office = Officelist[0]
    word = Office.attributes["Word"]
    spreadsheet = Office.attributes["Spreadsheet"]    
    presentation = Office.attributes["Presentation"]
    imageeditor = Office.attributes["ImageEditor"]
    calculator = Office.attributes["Calculator"]
    calendar = Office.attributes["Calendar"]
    pdf = Office.attributes["PDF"]
    notes = Office.attributes["Notes"]

    Multimedialist = domina.getElementsByTagName('Multimedia') 
    Multimedia = Multimedialist[0]
    music = Multimedia.attributes["Music"]
    pictures = Multimedia.attributes["Pictures"]    
    burn = Multimedia.attributes["Burn"]
    rip = Multimedia.attributes["Rip"]
    audioeditor = Multimedia.attributes["AudioEditor"]
    videoeditor = Multimedia.attributes["VideoEditor"]
    video = Multimedia.attributes["Video"]

    Developmentlist = domina.getElementsByTagName('Development') 
    Development = Developmentlist[0]
    editor = Development.attributes["Editor"]
    ide = Development.attributes["IDE"] 

    Systemlist = domina.getElementsByTagName('System') 
    System = Systemlist[0]
    install = System.attributes["Install"]
    filemanager = System.attributes["FileManager"]    
    archiver = System.attributes["Archiver"]
    search = System.attributes["Search"]
    konsole = System.attributes["Konsole"]
    package = System.attributes["Package"]
    screenshot = System.attributes["Screenshot"]

    Settingslist = domina.getElementsByTagName('Settings') 
    Settings = Settingslist[0]
    desktop = Settings.attributes["Desktop"]
    workspace = Settings.attributes["Workspace"]    
    appearance = Settings.attributes["Appearance"]
    language = Settings.attributes["Language"]
    panel = Settings.attributes["Panel"]
    wm = Settings.attributes["WM"]
    printer = Settings.attributes["Printer"]
    power = Settings.attributes["Power"]
    display = Settings.attributes["Display"]
    mouse = Settings.attributes["Mouse"]
    keyboard = Settings.attributes["Keyboard"]
    sound = Settings.attributes["Sound"]
    user = Settings.attributes["User"]
    time = Settings.attributes["Time"]
    update = Settings.attributes["Update"]
    sources = Settings.attributes["Sources"]
    network = Settings.attributes["Network"]
    ndis = Settings.attributes["Ndis"]
    share = Settings.attributes["Share"]
    


def appopen():
    if sys.argv[1] == "browser" or sys.argv[1] == "Browser":
        os.popen(browser.value + "&")
    elif sys.argv[1] == "mail" or sys.argv[1] == "Mail":
        os.popen(mail.value + "&")
    elif sys.argv[1] == "rss" or sys.argv[1] == "RSS":
        os.popen(rss.value + "&")
    elif sys.argv[1] == "im" or sys.argv[1] == "IM":
        os.popen(im.value + "&")
    elif sys.argv[1] == "irc" or sys.argv[1] == "IRC":
        os.popen(irc.value + "&")
    elif sys.argv[1] == "nfs" or sys.argv[1] == "NFS":
        os.popen(nfs.value + "&")
    elif sys.argv[1] == "skype" or sys.argv[1] == "Skype":
        os.popen(skype.value + "&")
    elif sys.argv[1] == "word" or sys.argv[1] == "Word":
        os.popen(word.value + "&")
    elif sys.argv[1] == "spreadsheet" or sys.argv[1] == "Spreadsheet":
        os.popen(spreadsheet.value + "&")
    elif sys.argv[1] == "presentation" or sys.argv[1] == "Presentation":
        os.popen(presentation.value + "&")
    elif sys.argv[1] == "imageeditor" or sys.argv[1] == "ImageEditor":
        os.popen(imageeditor.value + "&")
    elif sys.argv[1] == "calculator" or sys.argv[1] == "Calculator":
        os.popen(calculator.value + "&")
    elif sys.argv[1] == "calendar" or sys.argv[1] == "Calendar":
        os.popen(calendar.value + "&")
    elif sys.argv[1] == "pdf" or sys.argv[1] == "PDF":
        os.popen(pdf.value + "&")
    elif sys.argv[1] == "notes" or sys.argv[1] == "Notes":
        os.popen(notes.value + "&")
    elif sys.argv[1] == "music" or sys.argv[1] == "Music":
        os.popen(music.value + "&")
    elif sys.argv[1] == "pictures" or sys.argv[1] == "Pictures":
        os.popen(pictures.value + "&")
    elif sys.argv[1] == "burn" or sys.argv[1] == "Burn":
        os.popen(burn.value + "&")
    elif sys.argv[1] == "rip" or sys.argv[1] == "Rip":
        os.popen(rip.value + "&")
    elif sys.argv[1] == "audioeditor" or sys.argv[1] == "AudioEditor":
        os.popen(audioeditor.value + "&")
    elif sys.argv[1] == "videoeditor" or sys.argv[1] == "VideoEditor":
        os.popen(videoeditor.value + "&")
    elif sys.argv[1] == "video" or sys.argv[1] == "Video":
        os.popen(video.value + "&")
    elif sys.argv[1] == "editor" or sys.argv[1] == "Editor":
        os.popen(editor.value + "&")
    elif sys.argv[1] == "ide" or sys.argv[1] == "IDE":
        os.popen(ide.value + "&")
    elif sys.argv[1] == "install" or sys.argv[1] == "Install":
        os.popen(install.value + "&")
    elif sys.argv[1] == "filemanager" or sys.argv[1] == "FileManager":
        os.popen(filemanager.value + "&")
    elif sys.argv[1] == "archiver" or sys.argv[1] == "Archiver":
        os.popen(archiver.value + "&")
    elif sys.argv[1] == "search" or sys.argv[1] == "Search":
        os.popen(search.value + "&")
    elif sys.argv[1] == "konsole" or sys.argv[1] == "Konsole":
        os.popen(konsole.value + "&")
    elif sys.argv[1] == "package" or sys.argv[1] == "Package":
        os.popen(package.value + "&")
    elif sys.argv[1] == "screenshot" or sys.argv[1] == "Screenshot":
        os.popen(screenshot.value + "&")
    elif sys.argv[1] == "desktop" or sys.argv[1] == "Desktop":
        os.popen(desktop.value + "&")
    elif sys.argv[1] == "workspace" or sys.argv[1] == "Workspace":
        os.popen(workspace.value + "&")
    elif sys.argv[1] == "appearance" or sys.argv[1] == "Appearance":
        os.popen(appearance.value + "&")
    elif sys.argv[1] == "language" or sys.argv[1] == "Language":
        os.popen(language.value + "&")
    elif sys.argv[1] == "panel" or sys.argv[1] == "Panel":
        os.popen(panel.value + "&")
    elif sys.argv[1] == "wm" or sys.argv[1] == "WM":
        os.popen(wm.value + "&")
    elif sys.argv[1] == "printer" or sys.argv[1] == "Printer":
        os.popen(printer.value + "&")
    elif sys.argv[1] == "power" or sys.argv[1] == "Power":
        os.popen(power.value + "&")
    elif sys.argv[1] == "display" or sys.argv[1] == "Display":
        os.popen(display.value + "&")
    elif sys.argv[1] == "mouse" or sys.argv[1] == "Mouse":
        os.popen(mouse.value + "&")
    elif sys.argv[1] == "keyboard" or sys.argv[1] == "Keyboard":
        os.popen(keyboard.value + "&")
    elif sys.argv[1] == "sound" or sys.argv[1] == "Sound":
        os.popen(sound.value + "&")
    elif sys.argv[1] == "user" or sys.argv[1] == "User":
        os.popen(user.value + "&")
    elif sys.argv[1] == "time" or sys.argv[1] == "Time":
        os.popen(time.value + "&")
    elif sys.argv[1] == "update" or sys.argv[1] == "Update":
        os.popen(update.value + "&")
    elif sys.argv[1] == "sources" or sys.argv[1] == "Sources":
        os.popen(sources.value + "&")
    elif sys.argv[1] == "network" or sys.argv[1] == "Network":
        os.popen(network.value + "&")
    elif sys.argv[1] == "ndis" or sys.argv[1] == "Ndis":
        os.popen(ndis.value + "&")
    elif sys.argv[1] == "share" or sys.argv[1] == "Share":
        os.popen(share.value + "&")




def set():
    global browser, mail, rss, im, irc, nfs, skype
    global word, spreadsheet, presentation, imageeditor, calculator, calendar, pdf, notes
    global music, pictures, burn, rip, audioeditor, videoeditor, video
    global editor, ide
    global install, filemanager, archiver, search, konsole, package, screenshot
    global desktop, workspace, appearance, language, panel, wm, printer, power, display, mouse, keyboard, sound, user, time, update, sources, network, ndis, share
    if len(sys.argv) < 3:
        print "Usage: magi-kit [--set] [--show] <app> [command]"
    else:
        file = open(home + "/.magi-kit.xml", "w")
        if sys.argv[2] == "browser" or sys.argv[2] == "Browser":
            browser.value = sys.argv[3]
            print "set browser to " + browser.value
        elif sys.argv[2] == "mail" or sys.argv[2] == "Mail":
            mail.value = sys.argv[3]
            print "set mail to " + mail.value
        elif sys.argv[2] == "rss" or sys.argv[2] == "RSS":
            rss.value = sys.argv[3]
            print "set rss to " + rss.value
        elif sys.argv[2] == "im" or sys.argv[2] == "IM":
            im.value = sys.argv[3]
            print "set im to " + im.value
        elif sys.argv[2] == "irc" or sys.argv[2] == "IRC":
            irc.value = sys.argv[3]
            print "set irc to " + irc.value
        elif sys.argv[2] == "nfs" or sys.argv[2] == "NFS":
            nfs.value = sys.argv[3]
            print "set nfs to " + nfs.value
        elif sys.argv[2] == "skype" or sys.argv[2] == "Skype":
            skype.value = sys.argv[3]
            print "set skype to " + skype.value
        elif sys.argv[2] == "word" or sys.argv[2] == "Word":
            word.value = sys.argv[3] 
        elif sys.argv[2] == "spreadsheet" or sys.argv[2] == "Spreadsheet":
            spreadsheet.value = sys.argv[3] 
        elif sys.argv[2] == "presentation" or sys.argv[2] == "Presentation":
            presentation.value = sys.argv[3] 
        elif sys.argv[2] == "imageeditor" or sys.argv[2] == "ImageEditor":
            imageeditor.value = sys.argv[3] 
        elif sys.argv[2] == "calculator" or sys.argv[2] == "Calculator":
            calculator.value = sys.argv[3] 
        elif sys.argv[2] == "calendar" or sys.argv[2] == "Calendar":
            calendar.value = sys.argv[3] 
        elif sys.argv[2] == "pdf" or sys.argv[2] == "PDF":
            pdf.value = sys.argv[3] 
        elif sys.argv[2] == "notes" or sys.argv[2] == "Notes":
            notes.value = sys.argv[3] 
        elif sys.argv[2] == "music" or sys.argv[2] == "Music":
            music.value = sys.argv[3] 
        elif sys.argv[2] == "pictures" or sys.argv[2] == "Pictures":
            pictures.value = sys.argv[3] 
        elif sys.argv[2] == "burn" or sys.argv[2] == "Burn":
            burn.value = sys.argv[3] 
        elif sys.argv[2] == "rip" or sys.argv[2] == "Rip":
            rip.value = sys.argv[3] 
        elif sys.argv[2] == "audioeditor" or sys.argv[2] == "AudioEditor":
            audioeditor.value = sys.argv[3] 
        elif sys.argv[2] == "videoeditor" or sys.argv[2] == "VideoEditor":
            videoeditor.value = sys.argv[3] 
        elif sys.argv[2] == "video" or sys.argv[2] == "Video":
            video.value = sys.argv[3]
        elif sys.argv[2] == "editor" or sys.argv[2] == "Editor":
            editor.value = sys.argv[3] 
        elif sys.argv[2] == "ide" or sys.argv[2] == "IDE":
            ide.value = sys.argv[3]
        elif sys.argv[2] == "install" or sys.argv[2] == "Install":
            install.value = sys.argv[3] 
        elif sys.argv[2] == "filemanager" or sys.argv[2] == "FileManager":
            filemanager.value = sys.argv[3] 
        elif sys.argv[2] == "archiver" or sys.argv[2] == "Archiver":
            archiver.value = sys.argv[3] 
        elif sys.argv[2] == "search" or sys.argv[2] == "Search":
            search.value = sys.argv[3] 
        elif sys.argv[2] == "konsole" or sys.argv[2] == "Konsole":
            konsole.value = sys.argv[3] 
        elif sys.argv[2] == "package" or sys.argv[2] == "Package":
            package.value = sys.argv[3] 
        elif sys.argv[2] == "screenshot" or sys.argv[2] == "Screenshot":
            screenshot.value = sys.argv[3]
        elif sys.argv[2] == "desktop" or sys.argv[2] == "Desktop":
            desktop.value = sys.argv[3]
        elif sys.argv[2] == "workspace" or sys.argv[2] == "Workspace":
            workspace.value = sys.argv[3]
        elif sys.argv[2] == "appearance" or sys.argv[2] == "Appearance":
            appearance.value = sys.argv[3]
        elif sys.argv[2] == "language" or sys.argv[2] == "Language":
            language.value = sys.argv[3]
        elif sys.argv[2] == "panel" or sys.argv[2] == "Panel":
            panel.value = sys.argv[3]
        elif sys.argv[2] == "wm" or sys.argv[2] == "WM":
            wm.value = sys.argv[3]
        elif sys.argv[2] == "printer" or sys.argv[2] == "Printer":
            printer.value = sys.argv[3]
        elif sys.argv[2] == "power" or sys.argv[2] == "Power":
            power.value = sys.argv[3]
        elif sys.argv[2] == "display" or sys.argv[2] == "Display":
            display.value = sys.argv[3]
        elif sys.argv[2] == "mouse" or sys.argv[2] == "Mouse":
            mouse.value = sys.argv[3]
        elif sys.argv[2] == "keyboard" or sys.argv[2] == "Keyboard":
            keyboard.value = sys.argv[3]
        elif sys.argv[2] == "sound" or sys.argv[2] == "Sound":
            sound.value = sys.argv[3]
        elif sys.argv[2] == "user" or sys.argv[2] == "User":
            user.value = sys.argv[3]
        elif sys.argv[2] == "time" or sys.argv[2] == "Time":
            time.value = sys.argv[3]
        elif sys.argv[2] == "update" or sys.argv[2] == "Update":
            update.value = sys.argv[3]
        elif sys.argv[2] == "sources" or sys.argv[2] == "Sources":
            sources.value = sys.argv[3]
        elif sys.argv[2] == "network" or sys.argv[2] == "Network":
            network.value = sys.argv[3]
        elif sys.argv[2] == "ndis" or sys.argv[2] == "Ndis":
            ndis.value = sys.argv[3]
        elif sys.argv[2] == "share" or sys.argv[2] == "Share":
            share.value = sys.argv[3]

        dom.writexml(file)
        file.close()

def show():
    global browser, mail, rss, im, irc, nfs, skype
    global word, spreadsheet, presentation, imageeditor, calculator, calendar, pdf, notes
    global music, pictures, burn, rip, audioeditor, videoeditor, video
    global editor, ide
    global install, filemanager, archiver, search, konsole, package, screenshot
    global desktop, workspace, appearance, language, panel, wm, printer, power, display, mouse, keyboard, sound, user, time, update, sources, network, ndis, share
    if len(sys.argv) < 3:
        print "Usage: magi-kit [--set] [--show] <app> [command]"
    else:
        if sys.argv[2] == "browser" or sys.argv[2] == "Browser":
            print browser.value 
        elif sys.argv[2] == "mail" or sys.argv[2] == "Mail":
            print mail.value
        elif sys.argv[2] == "rss" or sys.argv[2] == "RSS":
            print rss.value
        elif sys.argv[2] == "im" or sys.argv[2] == "IM":
            print im.value
        elif sys.argv[2] == "irc" or sys.argv[2] == "IRC":
            print irc.value
        elif sys.argv[2] == "nfs" or sys.argv[2] == "NFS":
            print nfs.value
        elif sys.argv[2] == "skype" or sys.argv[2] == "Skype":
            print skype.value
        elif sys.argv[2] == "word" or sys.argv[2] == "Word":
            print word.value 
        elif sys.argv[2] == "spreadsheet" or sys.argv[2] == "Spreadsheet":
            print spreadsheet.value 
        elif sys.argv[2] == "presentation" or sys.argv[2] == "Presentation":
            print presentation.value 
        elif sys.argv[2] == "imageeditor" or sys.argv[2] == "ImageEditor":
            print imageeditor.value 
        elif sys.argv[2] == "calculator" or sys.argv[2] == "Calculator":
            print calculator.value 
        elif sys.argv[2] == "calendar" or sys.argv[2] == "Calendar":
            print calendar.value 
        elif sys.argv[2] == "pdf" or sys.argv[2] == "PDF":
            print pdf.value 
        elif sys.argv[2] == "notes" or sys.argv[2] == "Notes":
            print notes.value 
        elif sys.argv[2] == "music" or sys.argv[2] == "Music":
            print music.value 
        elif sys.argv[2] == "pictures" or sys.argv[2] == "Pictures":
            print pictures.value 
        elif sys.argv[2] == "burn" or sys.argv[2] == "Burn":
            print burn.value 
        elif sys.argv[2] == "rip" or sys.argv[2] == "Rip":
            print rip.value 
        elif sys.argv[2] == "audioeditor" or sys.argv[2] == "AudioEditor":
            print audioeditor.value 
        elif sys.argv[2] == "videoeditor" or sys.argv[2] == "VideoEditor":
            print videoeditor.value 
        elif sys.argv[2] == "video" or sys.argv[2] == "Video":
            print video.value
        elif sys.argv[2] == "editor" or sys.argv[2] == "Editor":
            print editor.value 
        elif sys.argv[2] == "ide" or sys.argv[2] == "IDE":
            print ide.value
        elif sys.argv[2] == "install" or sys.argv[2] == "Install":
            print install.value 
        elif sys.argv[2] == "filemanager" or sys.argv[2] == "FileManager":
            print filemanager.value 
        elif sys.argv[2] == "archiver" or sys.argv[2] == "Archiver":
            print archiver.value 
        elif sys.argv[2] == "search" or sys.argv[2] == "Search":
            print search.value 
        elif sys.argv[2] == "konsole" or sys.argv[2] == "Konsole":
            print konsole.value 
        elif sys.argv[2] == "package" or sys.argv[2] == "Package":
            print package.value 
        elif sys.argv[2] == "screenshot" or sys.argv[2] == "Screenshot":
            print screenshot.value
        elif sys.argv[2] == "desktop" or sys.argv[2] == "Desktop":
            print desktop.value
        elif sys.argv[2] == "workspace" or sys.argv[2] == "Workspace":
            print workspace.value
        elif sys.argv[2] == "appearance" or sys.argv[2] == "Appearance":
            print appearance.value
        elif sys.argv[2] == "language" or sys.argv[2] == "Language":
            print language.value
        elif sys.argv[2] == "panel" or sys.argv[2] == "Panel":
            print panel.value
        elif sys.argv[2] == "wm" or sys.argv[2] == "WM":
            print wm.value
        elif sys.argv[2] == "printer" or sys.argv[2] == "Printer":
            print printer.value
        elif sys.argv[2] == "power" or sys.argv[2] == "Power":
            print power.value
        elif sys.argv[2] == "display" or sys.argv[2] == "Display":
            print display.value
        elif sys.argv[2] == "mouse" or sys.argv[2] == "Mouse":
            print mouse.value
        elif sys.argv[2] == "keyboard" or sys.argv[2] == "Keyboard":
            print keyboard.value
        elif sys.argv[2] == "sound" or sys.argv[2] == "Sound":
            print sound.value
        elif sys.argv[2] == "user" or sys.argv[2] == "User":
            print user.value
        elif sys.argv[2] == "time" or sys.argv[2] == "Time":
            print time.value
        elif sys.argv[2] == "update" or sys.argv[2] == "Update":
            print update.value
        elif sys.argv[2] == "sources" or sys.argv[2] == "Sources":
            print sources.value
        elif sys.argv[2] == "network" or sys.argv[2] == "Network":
            print network.value
        elif sys.argv[2] == "ndis" or sys.argv[2] == "Ndis":
            print ndis.value
        elif sys.argv[2] == "share" or sys.argv[2] == "Share":
            print share.value



# Check if xml settings file is there
if (__name__ == "__main__"):
    if (os.path.exists(home + "/.magi-kit.xml")) is False : 
        print "magi-kit.xml does not exist. Created default one"
        initc()
    else:
        inito()
        if len(sys.argv) != 1:
            if sys.argv[1] == "--set":
                set()
            elif sys.argv[1] == "--show":
                show()
            else:
                appopen()
        else:
            print "Usage: magi-kit [--set] [--show] <app> [command]"
