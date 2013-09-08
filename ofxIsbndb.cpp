#include "ofxIsbndb.h"

ofxIsbndb::ofxIsbndb()
{
    //ctor
}

ofxIsbndb::~ofxIsbndb()
{
    //dtor
}

// Send URL to store refs from one isbn number ---------------
string ofxIsbndb::urlRequest_book(double _isbn){

    string urlRequest = urlRequest_basis();

    urlRequest += "/book";
    urlRequest += "/" + ofToString(_isbn, 0, 13, '0');

    return urlRequest;

}

// Return Basis URL needed ---------------
string ofxIsbndb::urlRequest_basis(){

    string urlRequest = "";

    urlRequest += URL_isbndbBasic;
    urlRequest += URL_ForXML;
    urlRequest += "/";
    urlRequest += apiKey_isbndb;

    return urlRequest;

}

//--------------------------------------------------------------
void ofxIsbndb::send(string _isbnNumber){
    double isbnToSend = ofToDouble(_isbnNumber);
    string url = "";
    
    if(isbnToSend<=0){
        // Can not sent, log it
        ofLogError() << "Request not sent : isbn not available : " << _isbnNumber;
        return;
    }
    
    if(m_bLoading==true){
        // Can not sent, log it
        ofLogError() << "Request already sent.";
        return;
    }
    
    // Build the url
    url = urlRequest_book(isbnToSend);
    // Send it to the world wide web
    ofLoadURLAsync(url,apiRequest_Name_Book);
    m_bLoading =true;
    // Log it
    ofLogNotice() << "Request sent : " << url;
    
    
}

//--------------------------------------------------------------
void ofxIsbndb::urlResponse(ofHttpResponse & response){
    
    ofxXmlSettings  xml;
    
    // 
    ofLogNotice() << "Response Got : Status=" << response.status << " Request Name=" << response.request.name;
    
	if(response.status==apiStatus_Found && response.request.name == apiRequest_Name_Book){
		xml.clear();
        xml.loadFromBuffer(response.data);
        
        // Response OK, we can decode
        ofLogNotice() << "Response OK, we'll add a book.";
        if(m_oBookReceived.fill(xml)){
            // Log the book added
            ofLogNotice() << "BOOK ADDED : " << m_oBookReceived.toString();
        }

		m_bLoading=false;
        
        
        
	}else{
		//
        if(response.status!=-1) m_bLoading=false;
	}
}
