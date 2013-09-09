// ----------------------------------------------------
//
// 2013/08/11 : Buis-les-baronnies (France) : created by Vj Dudley Smith (vj.dudley.smith@gmail.com). My first addon; be kind with him.
//
// ofxIsbndb : Addon built to connect to isbdn.org and retreive standard library datas
//
// ----------------------------------------------------
#pragma once

#include "ofMain.h"
#include "ofxXmlSettings.h"

#include "ofxIsbndb_define.h"
#include "ofxIsbndbBook.h"

class ofxIsbndb
{
    public:
        ofxIsbndb();
        virtual ~ofxIsbndb();

        string  urlRequest_book(string _isbn);
        void    urlResponse(ofHttpResponse &_response);
        void    send(string _isbnNumber);
    
    protected:
        ofxIsbndbBook   m_oBookReceived;
    public:
        ofxIsbndbBook   get_BookReceived(){return m_oBookReceived;};
    
    private:
        string urlRequest_basis();
    
    bool m_bLoading;

};

