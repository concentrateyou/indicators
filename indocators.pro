TEMPLATE = subdirs
SUBDIRS = core gui test
gui.depends = core
test.depends = core