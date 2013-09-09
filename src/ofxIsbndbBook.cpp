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
    
    bookToString = "isbn key=" + ofToString(m_iIsbnKey) + " : ";
    bookToString += "Title=" + m_sTitle + " : ";
    bookToString += "Author=" + m_sAuthor;
    
    return bookToString;
    
}

bool ofxIsbndbBook::fill(ofxXmlSettings &_xml){
    
    string content;
    _xml.copyXmlToString(content);
    
    ofLogNotice() << content;
    
    clear();
    
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
    m_iIsbnKey = ofToDouble(_xml.getValue(ISBN_API_TAG_isbn13, "unknown"));
    if(m_iIsbnKey<=0){
        ofLogError() << "ISBN Number not available." << m_iIsbnKey;
        return false;
    }
    
    m_sTitle = _xml.getValue(ISBN_API_TAG_title, "unknown");
    m_sAuthor = _xml.getValue(ISBN_API_TAG_author_data_name, "unknown");
    
    m_bIsFilled = true;
    return true;
    
}

void ofxIsbndbBook::clear(){
    m_bIsFilled = false;
    
    
    m_iIsbnKey = 0;
    m_sAuthor = "";
    m_sTitle = "";
    
}