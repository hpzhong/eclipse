#!/usr/bin/env python
#-*- coding:utf-8 -*-
"""
A script to test the gettext module
"""
import locale
import gettext  
catalogs = gettext.find("testapp", localedir="locale", all=True)  
print catalogs
t = gettext.translation('testapp', "locale", languages=[locale.getdefaultlocale()[0]], fallback=True)  
_=t.ugettext
boxnum = 7
catnum = 10
boxseq = 2
print _('This is a translatable string.')
print _("I have %(num)d boxes.") %{'num':boxnum}
print _("I have %d cats.") %(catnum)
print _("Therer are %(num)d cats in box N.O. %(seq)d.") %{'num':catnum, 'seq':boxseq}

