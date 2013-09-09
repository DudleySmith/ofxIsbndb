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
    string m_sTitle;
    string m_sAuthor;
    // Isbn key
    string m_sIsbnKey;
    // Is it ready to add in a library
    bool m_bIsFilled;

public:
    // ACCESSORS -------------------------------------------
    string get_title(){return m_sTitle;}
    void set_title(string _title){m_sTitle=_title;}
    
    string get_author(){return m_sAuthor;}
    void set_author(string _author){m_sAuthor=_author;}
    
    string get_isbnKey(){return m_sIsbnKey;}
    void set_isbnKey(string _isbnKey){m_sIsbnKey=_isbnKey;}
    
    double get_isFilled(){return m_bIsFilled;}
    
    // Fill with informations from isbndb.com
    bool fill(ofxXmlSettings &_xml);
    void clear();
    
    string toString();
    
};
