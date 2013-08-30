//
//  ofxIsbndbBook.cpp
//  readerUp_dummyScan
//
//  Created by Dudley Smith on 30/08/13.
//
//

#include "ofxIsbndbBook.h"

string ofxIsbndbBook::toString(){
    
    string bookToString = "";
    
    bookToString = "isbn key=" + ofToString(m_isbnKey) + " : ";
    bookToString += "Title=" + m_title + " : ";
    bookToString += "Author=" + m_author;
    
    return bookToString;
    
}

bool ofxIsbndbBook::fillWithInfos(ofxXmlSettings &_xml){
    
    string content;
    _xml.copyXmlToString(content);
    
    ofLogNotice() << content;
    
    // First check the content
    // 2 Tags mandatory : isbndb + datas
    
    if (!_xml.pushTag(ISBN_API_TAG_header)) {
        ofLogError() << "Can not retreive this tag." << ISBN_API_TAG_header;
        return false;
    }
    
    if (!_xml.pushTag(ISBN_API_TAG_data)) {
        ofLogError() << "Can not retreive this tag." << ISBN_API_TAG_data;
        return false;
    }
    
    // Get the isbn number and check it
    m_isbnKey = ofToDouble(_xml.getValue(ISBN_API_TAG_isbn13, "unknown"));
    if(m_isbnKey<=0){
        ofLogError() << "ISBN Number not available." << m_isbnKey;
        return false;
    }
    
    m_title = _xml.getValue(ISBN_API_TAG_title, "unknown");
    m_author = _xml.getValue(ISBN_API_TAG_author_data_name, "unknown");
    
    return true;
    
}
