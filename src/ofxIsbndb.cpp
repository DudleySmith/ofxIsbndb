#include "ofxIsbndb.h"

ofxIsbndb::ofxIsbndb()
{
    m_fTimeFromLastRequest=0;
}

ofxIsbndb::~ofxIsbndb()
{
    //dtor
}

// Send URL to store refs from one isbn number ---------------
string ofxIsbndb::urlRequest_book(string _isbn){

    string urlRequest = URL_isbndbBasic;

    urlRequest += "/books.xml";
    // Adding the key
    urlRequest += "?";
    urlRequest += URL_request_accessKey;
    urlRequest += "=";
    urlRequest += apiKey_isbndb;

    urlRequest += "&";
    urlRequest += URL_request_index1;
    urlRequest += "=";
    urlRequest += URL_request_index1_isbn;

    urlRequest += "&";
    urlRequest += URL_request_value1;
    urlRequest += "=";
    urlRequest += ofToString(_isbn, 0, 13, '0');

    ofLogVerbose() << urlRequest;
    /*
    // http://isbndb.com/api/books.xml?access_key=12345678&index1=isbn&value1=0596002068
    */
    return urlRequest;

}

//--------------------------------------------------------------
void ofxIsbndb::send(string _isbnNumber){

    double isbnToSend = ofToDouble(_isbnNumber);
    string url = "";

    setIsbnMessage("");

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
    url = urlRequest_book(_isbnNumber);

    // Send it to the world wide web
    ofLoadURLAsync(url,apiRequest_Name_Book);
    m_bLoading =true;
    m_fTimeFromLastRequest = ofGetElapsedTimef();

    // Log it
    ofLogVerbose() << "Request sent : " << url;


}

//--------------------------------------------------------------
void ofxIsbndb::urlResponse(ofHttpResponse & response){

    ofxXmlSettings  xml;

    //
    ofLogVerbose() << "Response Got : Status=" << response.status << " Request Name=" << response.request.name;

	if(response.status==apiStatus_Found || response.status==apiStatus_dontKnow){

        if(response.request.name == apiRequest_Name_Book){

            xml.clear();
            xml.loadFromBuffer(response.data);

            string xmlContent;
            xml.copyXmlToString(xmlContent);
            ofLogVerbose()<< xmlContent;

            // Response OK, we can decode
            ofLogVerbose() << "Response OK, we'll add a book.";
            if(m_oBookReceived.fill(xml)){
                // Log the book added
                ofLogVerbose() << "BOOK RECEIVED from isbndb.org : " << m_oBookReceived.toString();
                // Message to others
                addLineIsbnMessage("Votre livre est :");
                addLineIsbnMessage(m_oBookReceived.get_author() + " " + m_oBookReceived.get_title());
            }else{
                //
                addLineIsbnMessage("Ce livre n'a pas été trouvé dans la base de données. Il faut en essayer un autre.");
                //
            }
        }

		m_bLoading=false;

	}else{
        // Message to others
        setIsbnMessage("Il y a un probleme. Nous n'avons pas Internet.");
		//
        //if(response.status!=-1) m_bLoading=false;
        m_bLoading=false;
	}
}

// Time
float ofxIsbndb::waitingTime(){

    if(m_bLoading==false){
        return 0.0;
    }else{
        return (ofGetElapsedTimef() - m_fTimeFromLastRequest);
    }
}
