TEMPLATE = subdirs
SUBDIRS = app lib \
    myqmarkdowntextedit-app \
    myqmarkdowntextedit-lib \
    myqmarkdowntextedit-lib \
    myqmarkdowntextedit-app \
    myqmarkdowntextedit-lib \
    myqmarkdowntextedit-lib
app.file = qmarkdowntextedit-app.pro
lib.file = qmarkdowntextedit-lib.pro
app.depends = lib
