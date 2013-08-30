//
//  ofxIsbndbBook.h
//  readerUp_dummyScan
//
//  Created by Dudley Smith on 30/08/13.
//
//

#pragma once

#include "ofMain.h"
#include "ofxXmlSettings.h"

#include "ofxIsbndb_define.h"

class ofxIsbndbBook{
protected:
    // Book informations
    string m_title;
    string m_author;
    // Isbn key
    double m_isbnKey;

public:
    // ACCESSORS -------------------------------------------
    string get_title(){return m_title;}
    void set_title(string _title){m_title=_title;}
    
    string get_author(){return m_author;}
    void set_author(string _author){m_author=_author;}
    
    double get_isbnKey(){return m_isbnKey;}
    void set_isbnKey(double _isbnKey){m_isbnKey=_isbnKey;}
    
    // Fill with informations from isbndb.com
    bool fillWithInfos(ofxXmlSettings &_xml);
    
    string toString();
    
};
