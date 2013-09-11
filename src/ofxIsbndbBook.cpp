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
    
    bookToString = "isbn key=" + m_sIsbnKey + " : ";
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
    
    
    // Have a look if we have ehough results -------------------------------------------------------------
    int results = 0;
    string strResults;
    
    strResults = _xml.getAttribute(ISBN_API_TAG_BookList, ISBN_API_TAG_BookList_ATT_total_results, "unknown");
    results = ofToInt(strResults);
    
    if (results<=0) {
        ofLogError() << "No results.";
        return false;
    }
    
    _xml.pushTag(ISBN_API_TAG_BookList);
    
    
    
    // Get the isbn number and check it -------------------------------------------------------------------
    m_sIsbnKey = _xml.getAttribute(ISBN_API_TAG_BookData, ISBN_API_TAG_BookData_ATT_isbn13, "unknown");
    double isbnCheck = ofToDouble(m_sIsbnKey);

    if(isbnCheck<=0 || m_sIsbnKey.size()<=0 || m_sIsbnKey=="unknown"){
        ofLogError() << "ISBN Number not available." << m_sIsbnKey;
        return false;
    }
    
    _xml.pushTag(ISBN_API_TAG_BookData);
    
    
    m_sTitle = _xml.getValue(ISBN_API_TAG_Title, "unknown");
    m_sAuthor = _xml.getValue(ISBN_API_TAG_AuthorsText, "unknown");
    
    m_bIsFilled = true;
    return true;
    
}

void ofxIsbndbBook::clear(){
    m_bIsFilled = false;
    
    
    m_sIsbnKey = "";
    m_sAuthor = "";
    m_sTitle = "";
    
}