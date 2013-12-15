#!/usr/bin/env python


import sys
import getopt


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
        

if __name__ == '__main__':
    main()


