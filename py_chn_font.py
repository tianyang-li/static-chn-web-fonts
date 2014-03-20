#!/usr/bin/env python


import sys
import getopt
import codecs

import fontforge


def main():
    try:
        opts, args = getopt.getopt(sys.argv[1:], '', ['font='])
    except getopt.GetoptError as err:
        print >> sys.stderr, str(err)
        sys.exit(1)
    
    font_file = None
    
    for o, a in opts:
        if o == '--font':
            font_file = a
    
    if font_file == None:
        print >> sys.stderr, "no font file"
        sys.exit(1)
    
    chars = set([])
    
    for fi in args:
        f = codecs.open(fi, encoding='utf-8')
        for line in f:
            for c in line:
                chars.add(c)
        f.close()
    
    font = fontforge.open(font_file)
    
    ft_out = fontforge.font()
    ft_out.fontname = font.fontname
    ft_out.encoding = font.encoding
    
    for c in chars:
        try:
            uc = font[ord(c)]
            print ord(c),
            font.selection.select(uc)
            font.copy()
            ft_out.selection.select(uc)
            ft_out.paste()
        except TypeError:
            print "not found",
            pass
        print
    
    ft_out.save("partial.ttf")
    
    font.close()
    ft_out.close()
    

if __name__ == '__main__':
    main()


